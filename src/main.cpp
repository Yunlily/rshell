#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <sys/types.h>
#include <stdlib.h>
#include <pwd.h>
#include <vector>
#include "Cmd.h"
#include <queue>
#include "Connector.h"

using namespace std;
int main() {
    string input;
    while (1) {
        cout << "$ ";
        cin.clear ();
        getline(cin, input);
        if (input == "quit")
            return 0;
        bool pre = false;
        Cmd* cmd = new Cmd(input);
        Connector* Con = new Connector(input);
        cmd->parse ();
        queue<char*> cmdQ = cmd->GetCmdQ();
        queue<string> Conq = Con->getConQ();
        vector<char*> Com(1, NULL);
        if(!cmdQ.empty()) {
        Com[0] = cmdQ.front();
        pre = cmd->execute(Com);
        cmdQ.pop ();
        }
        while(!cmdQ.empty()) {
            bool flag = pre;
            string Op = Conq.front();
            if(Op == "And") {
                if(flag == true) {
                    Com[0] = cmdQ.front();
                    flag = cmd->execute(Com);
                    cmdQ.pop();
                }
                else {
                    cmdQ.pop();
                }
            }
            else {
                Com[0] = cmdQ.front();
                flag = cmd->execute(Com);
                cmdQ.pop();
            }
        }
        delete cmd;
        delete Con;
    }
    return 0;
}
