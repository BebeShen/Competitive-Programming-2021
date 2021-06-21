#include<bits/stdc++.h>
using namespace std;
struct d
{
    vector<char> ch;
    int count;
};
bool comp(const d &a, const d &b){
    return a.count < b.count;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        int n,m;
        cin>>n>>m;
        // init
        vector<d> s;
        s.resize(m);
        for(int i=0;i<m;i++)s[i].ch.resize(n);
        // get input
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                cin>>s[i].ch[j];
            }
        }
        for(int i=0;i<m;i++)s[i].count=0;
        // count sorted number
        for(int i=0;i<m;i++){
            for(int j=0;j<n-1;j++){
                for(int k=j;k<n;k++){
                    if(s[i].ch[j]>s[i].ch[k])s[i].count++;
                }
            }
        }
        stable_sort(s.begin(),s.end(),comp);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j)
                cout<<s[i].ch[j];
            cout<<"\n";
        }
        cout<<"\n";
    }
    
    
    return 0;
}