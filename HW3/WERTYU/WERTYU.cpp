#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char ch;
    string s;
    char origin[] = {'1','Q','A','Z','2','W','S','X','3','E','D','C','4','R','F','V','5','T','G','B','6','Y','H','N','7','U','J','M','8','I','K',',','9','O','L','.','0','P',';','/','-','[','\'','=',']','\\'};
    char after[] =  {'`','Q','A','Z','1','Q','A','Z','2','W','S','X','3','E','D','C','4','R','F','V','5','T','G','B','6','Y','H','N','7','U','J','M','8','I','K',',','9','O','L','.','0','P',';','-','[',']'};
    while(getline(cin,s)){
        if(cin.eof())break;
        for(int j=0;j<s.length();++j){
            if(s[j]==' ')cout<<' ';
            for(int i=0;i<46;++i){
                if(s[j]==origin[i])
                    cout<<after[i];
            }
        }
        cout<<"\n";
    }
    return 0;
}