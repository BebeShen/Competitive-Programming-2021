#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    string commands;
    int t;
    cin>>t;
    while(t--){
        int pointer = 0;
        vector<int>reg;
        vector<int>mem;
        int reg1,reg2;
        reg.resize(10);
        mem.resize(1000);
        int step = 0;
        while(cin>>commands){  
            mem.push_back(stoi(commands));
            if(pointer>=1000)break;
            if(commands=="100")break;
            else if(commands.at(0)=='2'){
                reg1 = commands.at(1) - '0';
                reg[reg1] = commands.at(2) - '0';
            }
            else if(commands.at(0)=='3'){
                reg1 = commands.at(1) - '0';
                reg[reg1] += (commands.at(2) - '0');
            }
            else if(commands.at(0)=='4'){
                reg1 = commands.at(1) - '0';
                reg[reg1] *= (commands.at(2) - '0');
            }
            else if(commands.at(0)=='5'){
                reg1 = commands.at(1) - '0';
                reg2 = commands.at(2) - '0';
                reg[reg1] = reg[reg2];
            }
            else if(commands.at(0)=='6'){
                reg1 = commands.at(1) - '0';
                reg2 = commands.at(2) - '0';
                reg[reg1] += reg[reg2];
            }
            else if(commands.at(0)=='7'){
                reg1 = commands.at(1) - '0';
                reg2 = commands.at(2) - '0';
                reg[reg1] *= reg[reg2];
            }
            else if(commands.at(0)=='8'){
                reg1 = commands.at(1) - '0';
                reg2 = commands.at(2) - '0';
                reg[reg1] = mem[reg[reg2]];
            }
            else if(commands.at(0)=='9'){
                reg1 = commands.at(1) - '0';
                reg2 = commands.at(2) - '0';
                mem[reg[reg2]] = reg[reg1];
            }
            else if(commands.at(0)=='0'){
                reg1 = commands.at(1) - '0';
                reg2 = commands.at(2) - '0';
                if(reg[reg2]!=0){
                    pointer = reg[reg1] - 1;
                }
            }
            for(int i=0;i<10;i++)reg[i]%=1000;
            step++;
            pointer++;
        }
        cout<<step<<endl;
    }
    return 0;
}