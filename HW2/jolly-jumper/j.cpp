#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    vector<int>v;
    vector<int>diff_v;
    while(cin>>n){
        if(cin.eof())break;
        v.resize(n);
        diff_v.resize(n-1);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        for(int i=1;i<n;i++){
            diff_v[i-1] = (abs(v[i]-v[i-1]));
        }
        sort(diff_v.begin(),diff_v.end());
        bool f = true;
        // for(int i=0;i<n-1;i++){
        //     cout<<diff_v[i]<<" ";
        // }
        for(int i=1;i<=n-1;i++){
            if(diff_v[i-1]!=i){
                f = false;
                break;
            }
        }
        if(!f) cout<<"Not jolly\n";
        else cout<<"Jolly\n";
    }
    return 0;
}