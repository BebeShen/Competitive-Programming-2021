#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    vector<vector<int> >v;
    int n;
    while (cin>>n) {
        if(n==0)break;
        int _row = 0, _col = 0;
        v.resize(n);
        vector<int>row,col;
        row.resize(n);
        col.resize(n);
        for(int i=0;i<n;++i)v[i].resize(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin>>v[i][j]; 
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(v[i][j] == 1){
                    row[i] ++;
                    col[j] ++;
                }
            }
        }
        bool row_f = true , col_f = true;
        for(int i=0;i<n;i++){
            // cout<<row[i]<<" ";
            if(row[i]%2!=0)_row++;
        }// cout<<"\n";
        for(int i=0;i<n;i++){
            // cout<<col[i]<<" ";
            if(col[i]%2!=0)_col++;
        }// cout<<"\n";
        if(_row>1 || _col>1 || (_col+_row==1)){
            cout<<"Corrupt\n";
        }
        else if(_row == 1 && _col == 1){
            int rowToChange,colToChange;
            for(int i=0;i<n;++i){
                if(row[i]%2==1)rowToChange=i+1;
                if(col[i]%2==1)colToChange=i+1;
            }
            cout<<"Change bit ("<<rowToChange<<","<<colToChange<<")\n";
        }
        else{
            cout<<"OK\n";
        }
    }
    
    
    return 0;
}