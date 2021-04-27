#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    int holiday1 = 5, holiday2 = 6;
    while(t--){
        int p,days;
        cin>>days>>p;
        vector<int>num_parties;
        num_parties.resize(p);
        int ans = 0;
        for(int i=0;i<p;++i)cin>>num_parties[i];
        // for(int i=0;i<p;++i)cout<<num_parties[i];
        for(int i=1;i<=days;++i){
            if(i%7==0||(i+1)%7==0)continue;
            for(int j=0;j<p;++j){
                if(i%num_parties[j]==0){
                    // cout<<"Match:"<<i<<" "<<num_parties[j]<<endl;
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}