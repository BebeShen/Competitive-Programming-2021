#include<bits/stdc++.h>
#define maxn 106
using namespace std;

int main(){
    int n;
    int _0=0, _3=0, _6=0, _9=0;
    cin >> n;
    vector<int> num;
    num.resize(n);
    for(int i=0;i<n;++i){
        cin>>num[i];
        switch(num[i]){
            case 0:
                _0++;break;
            case 3:
                _3++;break;
            case 6:
                _6++;break;
            case 9:
                _9++;break;
        }
    }
    int _6remain = _6%3, _3reserved = 0;
    _6 = (_6/3)*3;
    if(_6remain + _3>=3){
        _6 += _6remain;
        _3reserved = 3-_6remain;
        _3 = _3 - (3-_6remain);
    }
    _3 = (_3/3)*3;
    bool allzero = false;
    if(!_3&!_6&!_9)allzero = true;
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    // cout<<_9<<_6<<_6remain<<_3reserved<<_3<<_0<<endl;
    if(allzero)cout<<"None";
    else{
        for(int i=0;i<_9;++i)cout<<9<<" ";
        for(int i=0;i<_6;++i)cout<<6<<" ";
        for(int i=0;i<_3reserved;++i)cout<<3<<" ";
        for(int i=0;i<_3;++i)cout<<3<<" ";
        for(int i=0;i<_0;++i)cout<<0<<" ";
    }
    return 0;
}