#include "Base.h"
#include "Connector.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

//handle diffrent connectors
Connector::Connector(string inputcmd) {
    this->input = inputcmd;
    size_t com = input.find("#");
    if(com != string::npos) {
        input.erase(com);
    }
    for (unsigned it = 0; it < input.size(); it++) {
        if((input[it] == '&') && (input[it + 1] == '&')) {
            Conq.push("And");
        }
        else if((input[it] == ';') && (input[it + 1] == ' ')) {
            Conq.push("Semi");
        }
        else if((input[it] == '|') && (input[it + 1] == '|')) {
            Conq.push("Or");
        }
    }
}
//determine wherther to execute based on the connectors
bool Connector::execute() {
    return true;
}

queue<string> Connector::getConQ() {
    return Conq;
}
