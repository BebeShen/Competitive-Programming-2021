#include<bits/stdc++.h>
using namespace std;

int main(){
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    int t;
    cin>>t;
    string s;
    long ans=0;
    while(t--){
        cin>>s;
        if(s=="donate"){
            int k;
            cin>>k;
            ans+=k;
        }
        else if(s=="report"){
            cout<<ans<<"\n";
        }
    }
    return 0;
}