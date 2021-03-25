#include<bits/stdc++.h>
using namespace std;

int main(){
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    int n;
    int e,f,c;
    cin>>n;
    int bottle;
    while (n>0){
        cin>>e>>f>>c;
        bottle = e+f;
        int ans = 0;
        int remain, bottleget;
        while(bottle/c!=0){
            remain = bottle%c;
            bottleget = bottle/c;
            ans += bottleget;
            bottle = bottleget+remain;
        }
        cout<<ans<<endl;
        n--;
    }
    
    return 0;
}