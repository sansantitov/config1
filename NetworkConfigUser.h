#pragma once
#include <string>

constexpr auto networkConfigFileUser = "/tmp/networkuser.config";

class NetworkConfigUser final {
public:
    NetworkConfigUser();
    ~NetworkConfigUser();

    void setName(const std::string &name);
    void setLogin(const std::string &login);
    void setPass(const std::string &pass);

    const std::string& getName() const;
    const std::string& getLogin() const;
    const std::string& getPass() const;

private:
    std::string _name;
    std::string _login;
    std::string _pass;


    void readConfigUser();
    void writeConfigUser() const;

};



