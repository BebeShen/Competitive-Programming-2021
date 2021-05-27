#include<bits/stdc++.h>
using namespace std;
bool isComDiv(int i, int length){
    if(length % i != 0) return false;
    return true;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        // cout<<s;
        bool ans = false;
        int period = 0;
        int length = s.length();
        for(int i=1;i<=length/2;i++){
            bool test = true;
            // cout<<length%i<<endl;
            if(!isComDiv(i,length))
                continue;

            string tmp = s.substr(0,i);
            int groups = length/i;
            // cout<<"Groups:"<<groups<<endl;
            // cout<<"Substr length:"<<i<<endl;
            for(int j=0;j<groups;j++){
                // cout<<"start:"<<j*i<<", length:"<<j*i+i<<endl;
                string s_tmp = s.substr(j*i , i);
                // cout<<s_tmp <<" "<< tmp<<endl;
                if(tmp!=s_tmp){
                    test = false;
                    break;
                }
            }
            if(test){
                ans = true;
                period = i;
                break;
            }
        }
        if(ans && period!=0)cout<<period<<"\n";
        else if(period==0)cout<<length<<"\n";
        else cout<<"No solution\n";
        cout<<"\n";
    }
    
    return 0;
}