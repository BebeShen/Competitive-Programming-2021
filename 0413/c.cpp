#include<bits/stdc++.h>
using namespace std;

int main(){
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        vector<int>cluster;
        int enter;
        cin>>enter;
        cluster.resize(enter+1);
        for(int i=1;i<=enter;++i)cluster[i]=i;
        char ch;
        while (cin>>ch){   
            if(ch=='O')break;
            else if(ch=='E'){
                long ans=0;
                int asked;
                cin>>asked;
                for(int i=asked;;){
                    if(i==cluster[i])break;
                    ans+=abs(cluster[i]-i)%1000;
                    i = cluster[i];
                }
                cout<<ans<<"\n";
            }else if(ch=='I'){
                int a,b;
                cin>>a>>b;
                cluster[a] = b;
            }
        }
        
    }
    
    
    return 0;
}