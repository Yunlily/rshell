#ifndef Cmd_h
#define Cmd_h
#include <string>
#include <vector>
#include <queue>
#include "Base.h"
const int MAX_SIZE = 256;
using namespace std;

//Cmd class declaration
class Cmd: public Base {
protected:
    queue<char*> cmd;
    string input;
public:
    Cmd() {};
    ~Cmd() {};
    Cmd(string);
    bool execute();
    bool execute(vector<char*> );
    void parse();
    queue<char*> GetCmdQ();
    
};

#endif /* Cmd_h */