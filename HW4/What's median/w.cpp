#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    vector<int>v;
    int n;
    int c=1;
    while(cin>>n){
        v.push_back(n);
        sort(v.begin(),v.end());
        int l = v.size();
        // cout<<"case: "<<c++<<"\n---\n"<<v[l/2]<<","<<v[(l/2)+1]<<",length:"<<l<<"\n---\n";
        int ans = (l%2==0)?(v[l/2]+v[(l/2)-1])/2:v[l/2];
        cout<<ans<<"\n";
    }
    
    return 0;
}