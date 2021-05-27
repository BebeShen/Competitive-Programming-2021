#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        int q, slength = s.length();
        cin >> q;
        for(int i=0;i<q;++i){
            string tmp;
            bool f = false;
            cin>>tmp;
            int length = tmp.length();
            if(s.find(tmp)==std::string::npos)
                f = true;
            if(f) cout<<"n\n";
            else cout<<"y\n";
        }
    }
    
    return 0;
}