#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    vector<int>tuple;
    vector<int>next_tuple;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int round = 0;
        bool flag = false;
        tuple.resize(n);
        next_tuple.resize(n);
        for(int i=0;i<n;i++)cin>>tuple[i];
        while(!flag){
            bool test = true;
            for(int i=0;i<n;i++){
                if(tuple[i]!=0)test=false;
                if(i==n-1){
                    next_tuple[i] = abs(tuple[0] - tuple[i]);
                }else{
                    next_tuple[i] = abs(tuple[i] - tuple[i+1]);
                }
            }
            if(test)flag = true;
            tuple = next_tuple;
            // for(int i=0;i<n;i++)cout<<tuple[i]<<" ";cout<<"\n";
            round++;
            if(round>1000){
                cout<<"LOOP\n";
                break;
            }
        }
        if(flag)cout<<"ZERO\n";
        t--;
    }
    
    return 0;
}