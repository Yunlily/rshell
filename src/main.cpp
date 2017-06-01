#include <iostream>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <pwd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <vector>
#include <sys/stat.h>
#include <queue>
#include <stack>
using namespace std;

//check for parenthesis
bool isPa(string input) {
    if (input == "(" || input == ")") {
        return true;
    }
    return false;
}

//parse the string according to the connectors
queue<char*> parse(string input) {
    queue<char*> cmd;
    if (!input.empty()) {
        size_t com = input.find("#");
        if (com != string::npos) {
            input.erase(com);
        }
        char* str = const_cast<char*> (input.c_str());
        char* token = strtok(str, ";&|");
        while (token != NULL) {
            cmd.push(token);
            token = strtok(NULL, ";&|");
        }
    }
    return cmd;
}

//check for connectors
bool isConnector(string input) {
    if (input == "&&" || input == "||" || input == ";" || input == "; ") {
        return true;
    }
    return false;
}

//parse the string after the parenthesis
queue<string> parseParen(string input) {
    queue<char*> cmd;
    queue<string> Cmd;
    if (!input.empty()) {
        size_t com = input.find("#");
        if (com != string::npos) {
            input.erase(com);
        }
        char* str = const_cast<char*> (input.c_str());
        char* token = strtok(str, " ");
        while(token != NULL) {
            cmd.push(token);
            token = strtok(NULL, " ");
        }
    }
    while (!cmd.empty()) {
        char* star = cmd.front();
        string s(star);
        size_t p1 = s.find("(");
        size_t p2 = s.find(")");
        if(p1 > s.size() && p2 > s.size()) {
            Cmd.push(s);
        }
        else {
            int k = 0;
            while (p1 < s.size()) {
                k ++;
                s.erase(p1,1);
                p1 = s.find("(");
            }
            for (int j = 0; j < k; j ++) {
                Cmd.push("(");
            }
            if (p2 > s.size()) {
                Cmd.push(s);
            }
            else {
                int i = 0;
                while (p2 < s.size()) {
                    i++;
                    s.erase(p2,1);
                    p2 = s.find(")");
                }
                Cmd.push(s);
                for (int j = 0; j < i; j ++) {
                    Cmd.push(")");
                }
            }
        }
        cmd.pop();
    }
    return Cmd;
}

//get the connectors and push them into the queue
queue<string> getCon(string input) {
    queue<string> con;
    if (!input.empty()) {
        size_t com = input.find("#");
        if (com != string::npos) {
            input.erase(com);
        }
        for (size_t it = 0; it < input.size(); it++) {
            if ((input[it] == '&') &&(input[it+1] == '&')) {
                con.push("And");
            }
            if ((input[it] == ';') &&(input[it+1] == ' ')) {
                con.push("Semi");
            }
            if ((input[it] == '|') &&(input[it+1] == '|')) {
                con.push("Or");
            }
        }
    }
    return con;
}

//execute command
bool RunCmd(char* Comm) {
    bool ret = true;
    char* args[100] = {0};
    char* tokens = strtok(Comm," ");
    size_t i = 0;
    while (tokens != NULL) {
        string space = " ";
        char* sp = const_cast<char*>(space.c_str());
        if(tokens != sp)
            args[i] = tokens;
        i++;
        tokens = strtok(NULL, " ");
    }
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
    }
    else if (pid == 0) {
        if(execvp(args[0], args) == -1) {
            perror("exec");
            ret = false;
            exit(1);
        }
    }
    else {
        int status;
        if(waitpid(pid, &status, 0) == -1) {
        }
        if(WEXITSTATUS(status) != 0) {
            ret = false;
        }
    }
    return ret;
}

//deal with the test command
bool RunTestCmd(string input) {
    string command = input;
    if (command[command.size() - 1] == ' ') {
        command.erase(command.size() - 1);
    }
    if (command.size() <= 7) {
        return false;
    }
    if (command.find("-e") > command.size() && command.find("-f") > command.size() && command.find("-d") > command.size()){
        command.insert(5, "-e ");
    }
    string flag = command.substr(5,2);
    string path = command.substr(8);
    struct stat log;
    char* Path = const_cast<char*>(path.c_str());
    if (!stat(Path, &log)) {
        if (S_ISREG(log.st_mode)) {
            if(flag == "-f" || flag == "-e") {
                return true;
            }
            return false;
        }
        else if (S_ISDIR(log.st_mode)) {
            if (flag == "-d" || flag == "-e") {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

//check for either "[]" or test
bool isTestCmd(char* input) {
    string cmd = input;
    if (cmd.find("[") < cmd.size() || cmd.find("test") < cmd.size()) {
        return true;
    }
    return false;
}

//use test as a flag
string TransTestCmd(char* input) {
    string newInput;
    string Input = input;
    if (Input.find("[") < Input.size() && Input.find("]") < Input.size()) {
        newInput = "test" + Input.substr(1,Input.size()-3);
        return newInput;
    }
    return Input;
}

//output either "true" and "false"
void outResult(bool res) {
    if(res){
        cout << "(True)" << endl;
        return;
    }
    cout << "(False)" << endl;
}

//push the string to the queue according to different command or connectors
vector<string> Convert(queue<string> cmd) {
    vector<string> CCmd;
    vector<string> CCCmd;
    while (!cmd.empty()) {
        CCmd.push_back(cmd.front());
        cmd.pop();
    }
    unsigned i = 0;
    while (i < CCmd.size()) {
        if (isConnector(CCmd[i])){
            CCCmd.push_back(CCmd[i]);
            i ++;
        }
        if (isPa(CCmd[i])) {
            CCCmd.push_back(CCmd[i]);
            i ++;
        }
        else if (CCmd[i] == ";") {
            CCCmd.push_back("; ");
            i ++;
        }
        else {
            unsigned j = i;
            unsigned k = 0;
            string New;
            while (j < CCmd.size()&&!isConnector(CCmd[j]) && !isPa(CCmd[j])) {
                New = New + CCmd[j] + " ";
                j ++;
                k ++;
            }
            CCCmd.push_back(New);
            i = i + k;
        }
    }
    return CCCmd;
}


//run the whole command
int main() {
    string input;
    queue<char*> commands;
    queue<string> connector;
    do {
        cout << "$ ";
        cin.clear();
        getline(cin,input);
        if (input.find("(") > input.size() && input.find(")") > input.size()) {
            connector = getCon(input);
            commands = parse(input);
            bool isTest = false;
            bool Pre;
            string Con;
            string comm;
            char* arg;
            if (commands.size() > 0) {
                arg = commands.front();
                isTest = isTestCmd(arg);
                if (isTest) {
                    comm = TransTestCmd(arg);
                    Pre = RunTestCmd(comm);
                    outResult(Pre);
                }
                else {
                    Pre =RunCmd(arg);
                }
                commands.pop();
                while (!commands.empty()) {
                    Con = connector.front();
                    arg = commands.front();
                    if ((Con == "And" && Pre == true)|| Con == "Semi" || (Con == "Or" && Pre == false)) {
                        isTest = isTestCmd(arg);
                        if (isTest) {
                            comm = TransTestCmd(arg);
                            Pre = RunTestCmd(comm);
                            outResult(Pre);
                        }
                        else {
                            Pre =RunCmd(arg);
                        }
                    }
                    connector.pop();
                    commands.pop();
                }
            }
        }
        else {
            queue<string> cmd;
            cmd = parseParen(input);
            vector<string> CCmd;
            CCmd = Convert(cmd);
            queue<string> Con;
            bool isTest = false;
            bool Pre = true;
            unsigned i = 0;
            string comm;
            
            while (i < CCmd.size()) {
                string arg = CCmd[i];
                bool previous = Pre;
                if(arg == "("){
                }
                else if(arg == ")"){
                 if(i + 2 < CCmd.size()){
                     string next = CCmd[i + 1];
                     if(next == "||" && previous){
                         string nex = CCmd[i + 2];
                         if(nex == "("){
                            do{
                                i++;
                            }while(CCmd[i] != ")");
                         }
                     }
                 }   
                }
                else if (isConnector(arg)) {
                    if (i + 1 < CCmd.size()) {
                        string next = CCmd[i + 1];
                        char* ne = const_cast<char*>(next.c_str());
                        if ((arg == "&&" && Pre == true) || (arg == "Or" && Pre == false)) {
                            isTest = isTestCmd(ne);
                            if (isTest) {
                                comm = TransTestCmd(ne);
                                Pre = RunTestCmd(comm);
                                outResult(Pre);
                            }
                            else {
                                Pre =RunCmd(ne);
                            }
                        }
                        i++;
                    }
                    
                }
                else {
                        string now = CCmd[i];
                        char* no = const_cast<char*>(now.c_str());
                        isTest = isTestCmd(no);
                        if (isTest) {
                            comm = TransTestCmd(no);
                            Pre = RunTestCmd(comm);
                            outResult(Pre);
                        }
                        else {
                            Pre =RunCmd(no);
                        }
                    }
                i++;
            }
        }
    } while (input != "exit");
    return 0;
}

