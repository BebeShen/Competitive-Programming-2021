#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int no_group;
    while(cin>>no_group){
        if(no_group==0)break;
        string s;
        cin>>s;
        int length = s.length();
        int t = (length / no_group);
        for(int i=0;i<no_group;i++){
            for(int j=t-1;j>=0;j--){
                cout<<s[i*t+j];
            }
        }
        cout<<endl;
    }
    return 0;
}