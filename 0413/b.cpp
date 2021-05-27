#include<bits/stdc++.h>
using namespace std;

typedef struct pos{
    int x;
    int y;
}p;

int main(){
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>x;
        vector<int>y;
        vector<int>w;
        vector<pos>v;
        x.resize(n);
        y.resize(n);
        w.resize(n);
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i]>>w[i];
            p tmp;
            tmp.x = x[i],tmp.y = y[i]; 
            v.push_back(tmp);
            tmp.x = x[i]+w[i],tmp.y = y[i]; 
            v.push_back(tmp);
            tmp.x = x[i],tmp.y = y[i]+w[i]; 
            v.push_back(tmp);
            tmp.x = x[i]+w[i],tmp.y = y[i]+w[i]; 
            v.push_back(tmp);
        }
        int _max = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<v.size();j++){
                _max = max( abs(v[j].x - x[i])*abs(v[j].x - x[i])+abs(v[j].y - y[i])*abs(v[j].y - y[i]) ,_max);
            }
        }
        cout<<_max<<"\n";
    }
    
    return 0;
}