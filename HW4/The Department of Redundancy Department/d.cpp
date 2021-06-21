#include<bits/stdc++.h>
using namespace std;
struct d
{
    int key;
    int value;
};
int find(vector<d>dict, int n){
    for(int i=0;i<dict.size();++i){
        if(n==dict[i].key)return i;
    }
    return -1;
}
int main(){
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);
    int n,_key;
    // map<int,int> dict;
    // while (cin>>n){
    //     if( dict.find(n) == dict.end() ){
    //         cout<<"No find.\n";
    //         dict.insert(pair<int,int>(n,1));
    //     }
    //     else{
    //         // cout<<n<<","<<dict[n]<<"\n";
    //         dict[n]++;
    //     }
    // }
    // for(map<int,int>::iterator iter=dict.begin();iter!=dict.end();iter++){
    //     cout<<iter->first<<" "<<iter->second<<"\n";
    // }
    vector<d>dict;
    while (cin>>n){
        if( (_key=find(dict,n))==-1 ){
            d tmp;
            tmp.key = n;
            tmp.value = 1;
            dict.push_back(tmp);
        }
        else{
            dict[_key].value++;
        }
    }
    for(int i=0;i<dict.size();++i){
        cout<<dict[i].key<<" "<<dict[i].value<<"\n";
    }
    return 0;
}