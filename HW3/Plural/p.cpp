#include<bits/stdc++.h>
using namespace std;
bool isCon(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return false;
    return true;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int l,n;
    cin>>l>>n;
    map<string,string>irregular_dict;
    for(int i=0;i<l;i++){
        string sin,pul;
        cin>>sin>>pul;
        irregular_dict.insert(pair<string,string>(sin,pul));
    }    
    for(int i=0;i<n;++i){
        string tmp;
        cin>>tmp;
        int length = tmp.length();
        if(irregular_dict.find(tmp)!=irregular_dict.end()){
            // Find it in dict
            cout<<irregular_dict.find(tmp)->second<<"\n";
        }
        else if(tmp[length-1]=='y' && isCon(tmp[length-2])){
            // end w/ y
            tmp[length-1] = 'i';
            tmp += "es";
            cout<<tmp<<"\n";
        }
        else if((tmp[length-1]=='o')||(tmp[length-1]=='s')||(tmp[length-2]=='c'&& tmp[length-1]=='h')||(tmp[length-2]=='s'&& tmp[length-1]=='h')||(tmp[length-1]=='x')){
            tmp+="es";
            cout<<tmp<<"\n";
        }
        else{
            tmp+="s";
            cout<<tmp<<"\n";
        }
    }
    return 0;
}