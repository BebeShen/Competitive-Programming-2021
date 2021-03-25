#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,m;
    int round = 0;
    vector<vector<char> >field;
    while(cin>>n>>m){
        if(n==0 && m==0)break;
        round++;
        // resize
        field.resize(n);
        for(int i=0;i<n;i++)field[i].resize(m);
        // input field
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>field[i][j];
                if(field[i][j]=='.'){
                    field[i][j] = '0';
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(field[i][j]=='*'){
                    if(i-1>=0 && field[i-1][j]!='*')field[i-1][j]++;
                    if(i+1<n && field[i+1][j]!='*')field[i+1][j]++;
                    if(j-1>=0 && field[i][j-1]!='*')field[i][j-1]++;
                    if(j+1<m && field[i][j+1]!='*')field[i][j+1]++;
                    if((i-1>=0 && j-1>=0) && field[i-1][j-1]!='*')field[i-1][j-1]++;
                    if((i+1<n && j-1>=0) && field[i+1][j-1]!='*')field[i+1][j-1]++;
                    if((i-1>=0 && j+1<m) && field[i-1][j+1]!='*')field[i-1][j+1]++;
                    if((i+1<n && j+1<m) && field[i+1][j+1]!='*')field[i+1][j+1]++;
                }
            }
        }
        cout<<"Field #"<<round<<":\n";
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cout<<field[i][j];
            }cout<<"\n";
        }
        cout<<"\n";
    }
    
    return 0;
}