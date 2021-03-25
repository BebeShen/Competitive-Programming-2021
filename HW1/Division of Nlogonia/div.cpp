#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    int p_x,p_y;
    while(cin>>n){
        if(n==0)break;
        cin>>p_x>>p_y;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            if(x==p_x||y==p_y)cout<<"divisa\n";
            else if(x>p_x && y>p_y)cout<<"NE\n";
            else if(x<p_x && y>p_y)cout<<"NO\n";
            else if(x>p_x && y<p_y)cout<<"SE\n";
            else if(x<p_x && y<p_y)cout<<"SO\n";
        }
    }
    
    return 0;
}