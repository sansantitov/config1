#include "NetworkConfigMsg.h"
#include <filesystem>
#include <fstream>


NetworkConfigMsg::NetworkConfigMsg() {
    readConfigMsg();
}

NetworkConfigMsg::~NetworkConfigMsg() {
    writeConfigMsg();
}	

void NetworkConfigMsg::setText(const std::string& text) {
    _text = text;
}

void NetworkConfigMsg::setSender(const std::string& sender) {
    _sender = sender;
}
void NetworkConfigMsg::setReceiver(const std::string& receiver) {
    _receiver = receiver;
}


const std::string& NetworkConfigMsg::getText() const {
    return _text;
}

const std::string& NetworkConfigMsg::getSender() const {
    return _sender;
}
const std::string& NetworkConfigMsg::getReceiver() const {
    return _receiver;
}


void NetworkConfigMsg::readConfigMsg() {
    std::fstream file(networkConfigFileMsg, std::ios::in);
    auto permissions = std::filesystem::perms::group_all |
        std::filesystem::perms::others_all;
    std::filesystem::permissions(networkConfigFileMsg, permissions,
        std::filesystem::perm_options::remove);

	const std::string delimiter = ":";
	if (file.is_open()) {
		std::string line;
		std::string name;
		std::string value;

		while (std::getline(file, line)) {

            size_t delimiterPosition = line.find(delimiter);
			if (delimiterPosition > 0) {
				name = line.substr(0, delimiterPosition);
				value = line.substr(delimiterPosition+1);
				
                if (name == "Text") {
                    _text = value;
					
				}
                else if (name == "Sender") {
                    _sender = value;
				}
                else if (name == "Receiver") {
                    _receiver = value;
                }
			}
		}

	}

    file.close();

}

void NetworkConfigMsg::writeConfigMsg() const {
    std::fstream file(networkConfigFileMsg, std::ios::out);
    file << "Text:" << _text << "\n";
    file << "Sender:" << _sender << "\n";
    file << "Receiver:" << _receiver << "\n";
	file.close();
}
