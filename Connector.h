
#ifndef Connector_h
#define Connector_h
#include <string>
#include <queue>
#include "Base.h"
using namespace std;

//connector declaration
class Connector:public Base { 
protected:
    string input;
    queue<string> Conq;
public:
    Connector() {};
    ~Connector() {};
    Connector(string);
    bool execute();
    queue<string> getConQ();
    
};

#endif /* Connector_h */
