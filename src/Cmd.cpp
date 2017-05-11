#include "Cmd.h"
#include <iostream>
#include <unistd.h>
#include <vector>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;
Cmd::Cmd(string inputcmd) {
    this->input = inputcmd;
    size_t com = input.find("#");
    if (com != string::npos) {
        input.erase(com);
    }
}

//parse the string
void Cmd::parse() {
    if(!input.empty()) {
    char* str = const_cast<char*> (input.c_str());
    char* token = strtok(str, ";&|");
    while(token != NULL) {
        cmd.push(token);
        token = strtok(NULL, ";&|");
        }
    }
}

//determine whether to execute or not
bool Cmd::execute() {
    return true;
}

//construct a queue to get commands
queue<char*> Cmd::GetCmdQ() {
    return cmd;
}

//execute command
bool Cmd::execute(vector<char*> Comm) {
    bool ret = true;
    if(!Comm.empty()) {
        size_t length = Comm.size();
        length = (unsigned)length;
        char* args[100] = {0};
        char* tokens = strtok(Comm[0]," ");
        size_t i = 0;
        while(tokens != NULL) {
            string space = " ";
            char* sp = const_cast<char*>(space.c_str());
            if(tokens != sp)
            args[i] = tokens;
            i++;
            tokens = strtok(NULL, " ");
            }
        pid_t pid = fork();
        if(pid == -1) {
            perror("fork");
        }
        else if(pid == 0) {
            //child
            if(execvp(args[0], args) == -1) {
                perror("exec");
                ret = false;
                exit(1);
            }
        }
        else {
            //parent
            int status;
            if(waitpid(pid, &status, 0) == -1) {
            //perror("wait");
            }
            if(WEXITSTATUS(status) != 0) {
                ret = false;
            }
        }
    }
    return ret;
}
