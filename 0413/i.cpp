#include<bits/stdc++.h>
using namespace std;

// 0~9
char top[10] = {'-',' ','-','-',' ','-','-','-','-','-'};

// 0~9
// 0:left 1:right 2:both
int Up[10] = {2,1,1,1,2,0,0,1,2,2};
// 0~9
char mid[10] = {' ',' ','-','-','-','-','-',' ','-','-'};
// 0~9
// 0:left 1:right 2:both
int Down[10] = {2,1,0,1,1,1,2,1,2,1};

// 0~9
char bot[10] = {'-',' ','-','-',' ','-','-',' ','-','-'};

void display(int layer,int s,char number, bool eol){
    int n = number - '0';
    switch (layer)
    {
    case 0:
        cout<<" ";
        for(int i=0;i<s;i++)cout<<top[n];
        cout<<" ";
        break;
    case 1:
            if(Up[n]==2||Up[n]==0){
                cout<<"|";
            }
            else{
                cout<<" ";
            }
            for(int j=0;j<s;j++)cout<<" ";
            if(Up[n]==2||Up[n]==1){
                cout<<"|";
            }
            else{
                cout<<" ";
            }
        break;
    case 2:
        cout<<" ";
        for(int i=0;i<s;i++)cout<<mid[n];
        cout<<" ";
        break;
    case 3:
            if(Down[n]==2||Down[n]==0){
                cout<<"|";
            }   
            else{
                cout<<" ";
            }
            for(int j=0;j<s;j++)cout<<" ";
            if(Down[n]==2||Down[n]==1){
                cout<<"|";
            }
            else{
                cout<<" ";
            }
        
        break;
    case 4:
        cout<<" ";
        for(int i=0;i<s;i++)cout<<bot[n];
        cout<<" ";
        break;
    default:
        break;
    }
}

int main(){
    int s;
    string n;
    while(cin>>s>>n){
        if(s==0&&n=="0")break;
        for(int i=0;i<5;i++){
            if(i==1||i==3){
                for(int z=0;z<s;z++){
                    for(int j=0;j<n.length();j++){
                        bool flag = false;
                        if(j==n.length()-1)flag = true;
                        display(i,s,n[j],flag);
                        if(j!=n.length()-1)cout<<" ";
                    }
                cout<<"\n";
                }
            }
            else{
                for(int j=0;j<n.length();j++){
                    bool flag = false;
                    if(j==n.length()-1)flag = true;
                    display(i,s,n[j],flag);
                    if(j!=n.length()-1)cout<<" ";
                }
                cout<<"\n";
            }
        }
        cout<<"\n";
    }
    return 0;
}