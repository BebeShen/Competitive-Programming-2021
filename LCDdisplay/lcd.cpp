#include<bits/stdc++.h>
using namespace std;
/*
    0:"   "
    1:" - "
    2:"  |"
    3:"|  "
    4:"| |"
*/
int Num[10][5] = { 
	{1,4,0,4,1},/*0*/ 
	{0,2,0,2,0},/*1*/ 
	{1,2,1,3,1},/*2*/ 
	{1,2,1,2,1},/*3*/ 
	{0,4,1,2,0},/*4*/ 
	{1,3,1,2,1},/*5*/ 
	{1,3,1,4,1},/*6*/ 
	{1,2,0,2,0},/*7*/ 
	{1,4,1,4,1},/*8*/ 
	{1,4,1,2,1}/*9*/ 
};
void draw(int ch,int s,int line){
    int row,col;
    col = s+2;
    row = 2*s+3;
    switch (Num[ch][line])
    {
        case 0:
            cout<<" ";
            for(int i=0;i<s;++i)cout<<" ";
            cout<<" ";
            break;
        case 1:
            cout<<" ";
            for(int i=0;i<s;++i)cout<<"-";
            cout<<" ";
            break;
        case 2:
            cout<<" ";
            for(int j=0;j<s;++j)cout<<" ";
            cout<<"|";
            break;
        case 3:
            cout<<"|";
            for(int j=0;j<s;++j)cout<<" ";
            cout<<" ";
            break;
        case 4:
            cout<<"|";
            for(int j=0;j<s;++j)cout<<" ";
            cout<<"|";
            break;
        default:
            break;
    }
    
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int s;
    string n;
    while(cin>>s>>n){
        if(s==0&&n=="0")break;
        for(int j=0;j<5;++j){
            if(j==1||j==3){
                for(int z=0;z<s;z++){
                    for(int i=0;i<n.length();i++){
                        int ch = n[i] - '0';
                        draw(ch,s,j);
                        if(i!=n.length()-1)cout<<" ";
                    }cout<<"\n";
                };
            }else{
                for(int i=0;i<n.length();i++){
                    int ch = n[i] - '0';
                    draw(ch,s,j);
                    if(i!=n.length()-1)cout<<" ";
                }cout<<"\n";
            }
        }
        cout<<"\n";
    }
    
    return 0;
}