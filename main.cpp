
#include "NetworkConfigUser.h"
#include "NetworkConfigMsg.h"
#include <ostream> 
#include <string>
#include <iostream>


int main() {
    NetworkConfigUser configUser;
    std::cout << "Initial user config:\n";
    std::cout << "Name: " << configUser.getName() << "\n";
    std::cout << "Login: " << configUser.getLogin() << "\n";
    std::cout << "Pass: " << configUser.getPass() << "\n\n";

    const std::string newName = "New User";
    configUser.setName(newName);
    const std::string newLogin = "New Login";
    configUser.setLogin(newLogin);
    const std::string newPass = "New Pass";
    configUser.setPass(newPass);

    std::cout << "Current user config:\n";
    std::cout << "Name: " << configUser.getName() << "\n";
    std::cout << "Login: " << configUser.getLogin() << "\n";
    std::cout << "Pass: " << configUser.getPass() << "\n\n";

	
    NetworkConfigMsg configMsg;
    std::cout << "Initial message config:\n";
    std::cout << "Text: " << configMsg.getText() << "\n";
    std::cout << "Sender: " << configMsg.getSender() << "\n";
    std::cout << "Receiver: " << configMsg.getReceiver() << "\n\n";

    const std::string newText = "New Message";
    configMsg.setText(newText);
    const std::string newSender = "New Sender";
    configMsg.setSender(newSender);
    const std::string newReceiver = "New Receiver";
    configMsg.setReceiver(newReceiver);

    std::cout << "Current message config:\n";
    std::cout << "Text: " << configMsg.getText() << "\n";
    std::cout << "Sender: " << configMsg.getSender() << "\n";
    std::cout << "Receiver: " << configMsg.getReceiver() << "\n\n";

};
