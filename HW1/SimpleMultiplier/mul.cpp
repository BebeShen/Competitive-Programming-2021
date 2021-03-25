#include<iostream>
#include<string>
#define maxn 100
using namespace std;

int main(){
    long long int n;
    cin >> n;
    for(int i=0;i<n;++i){
        long m,_m; 
        cin>>_m>>m;
        cout<<_m*m<<"\n";
    }
    return 0;
}