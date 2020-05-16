#ifndef SCRIPT_H
#define SCRIPT_H

#include <string>

class Script {
public:
    virtual void sendMessage(std::string& strMessage) = 0;
    virtual ~Script() { }
};

#endif