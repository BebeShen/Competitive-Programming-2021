#include<bits/stdc++.h>
using namespace std;

int main(){
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    char c;
    vector<vector<char> >v;
    while(cin>>c){
        int m,n;
        if(c=='X')break;
        else if(c=='I'){
            cin>>m>>n;
            v.resize(n);
            for(int i=0;i<n;i++)v[i].resize(m);
        }
        else if(c=='C'){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    v[i][j] = 'O';
                }
            }
        }
        else if(c=='L'){
            int row,col;
            cin>>col>>row;
            char color;
            cin>>color;
            v[row-1][col-1] = color;
        }
        else if(c=='V'){
            
        }
        else if(c=='H'){
            
        }
        else if(c=='K'){
            
        }
        else if(c=='F'){
            
        }
        else if(c=='S'){
            string tmp;
            cin>>tmp;
            cout<<tmp<<"\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    cout<<v[i][j];
                cout<<"\n";       
            }
        }
    }
    
    return 0;
}