#include<bits/stdc++.h>
using namespace std;

int main(){
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL); 
    while(true){
        if(cin.eof())break;
        char ch;
        string s;
        string tmp = "";
        int tmp_length = 0;
        bool flag = true;
        while (getline(cin,s)){
            // cout<<s;
            for(int i=0;i<s.length();++i){
                ch = s[i];
                if(ch=='\"'){
                    if(flag){
                        cout<<"``"; 
                    }
                    else{
                        cout<<"''";
                    }
                    flag=!flag;
                }
                else{
                    cout<<ch;
                }
            }
        }
        
    }
    
    return 0;
}