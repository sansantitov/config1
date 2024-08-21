#include "NetworkConfigUser.h"
#include <filesystem>
#include <fstream>


NetworkConfigUser::NetworkConfigUser() {
    readConfigUser();
}

NetworkConfigUser::~NetworkConfigUser() {
    writeConfigUser();
}	

void NetworkConfigUser::setName(const std::string& name) {
    _name = name;
}

void NetworkConfigUser::setLogin(const std::string& login) {
    _login = login;
}
void NetworkConfigUser::setPass(const std::string& pass) {
    _pass = pass;
}


const std::string& NetworkConfigUser::getName() const {
    return _name;
}

const std::string& NetworkConfigUser::getLogin() const {
    return _login;
}
const std::string& NetworkConfigUser::getPass() const {
    return _pass;
}


void NetworkConfigUser::readConfigUser() {
    std::fstream file(networkConfigFileUser, std::ios::in);
    auto permissions = std::filesystem::perms::group_all |
        std::filesystem::perms::others_all;
    std::filesystem::permissions(networkConfigFileUser, permissions,
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
				
                if (name == "Name") {
                    _name = value;
					
				}
                else if (name == "Login") {
                    _login = value;
				}
                else if (name == "Pass") {
                    _pass = value;
                }
			}
		}

	}

    file.close();

}

void NetworkConfigUser::writeConfigUser() const {
    std::fstream file(networkConfigFileUser, std::ios::out);
    file << "Name:" << _name << "\n";
    file << "Login:" << _login << "\n";
    file << "Pass:" << _pass << "\n";
	file.close();
}
