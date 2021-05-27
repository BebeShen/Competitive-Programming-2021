#include<bits/stdc++.h>
using namespace std;

long re(long n){
    while (n%10==0)
    {
        n/=10;
    }
    return n%10;
}

int main(){
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    vector<int>v;
    long p,q;
    long ans;
    while(cin>>p>>q){
        ans = 0;
        if(p<0&&q<0)break;
        for(int i=p;i<=q;i++){
            ans+=re(i);
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}