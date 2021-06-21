#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v;
        v.resize(n);
        for(int i=0;i<n;++i){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int median = v[(n/2)];
        int ans = 0;
        for(int i=0;i<n;++i){
            ans += abs(v[i]-median);
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}