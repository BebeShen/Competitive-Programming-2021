#include<bits/stdc++.h>
using namespace std;
int getCycleLength(int n){
    int length = 1;
    while(n!=1){
        if(n%2==0)n=n/2;
        else n=3*n+1;
        length++;
    }
    //cout<<n<<"length:"<<length<<"\n";
    return length;
}
int doCycle(int l, int u){
    int maxLength = -1;
    for(int i=l;i<=u;++i){
        maxLength = max(maxLength, getCycleLength(i));
    }
    return maxLength;
}
int main(){
    int l,u,n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        if(n>m){
            u = n;
            l = m;
        }else{
            u = m;
            l = n;
        }
        cout<<n<<" "<<m<<" "<<doCycle(l,u)<<"\n";
    }
    return 0;
}