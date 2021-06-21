#include<bits/stdc++.h>
using namespace std;
void flip(vector<int> &v, const int length){
    for(int i=0;i<length/2;++i){
        // swap
        int tmp = v[i];
        v[i] = v[length-i-1];
        v[length-i-1] = tmp;
    }
    // cout<<"\nAfter flip:\n";
    // for(auto &i:v)
    //     cout<<i<<" ";
    // cout<<"\n-----\n";
}
int findMax(const vector<int> &v, const int length){
    int max = -1, max_pos;
    
    for(int i=0;i<length;++i){
        if(v[i]>max){
            max = v[i];
            max_pos = i;
        }
    }
    // cout<<"\nmax pos:"<<max_pos;
    return max_pos;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    string s;
    while (getline(cin,s)){
        if(cin.eof())break;
        vector<int>stacks;
        cout<<s<<"\n";
        string token, delim = " ";
        int pos;
        while((pos = s.find(delim))!=std::string::npos){
            token = s.substr(0, pos);
            s.erase(0, pos + delim.length());
            // cout<<stoi(token)<<",";
            stacks.push_back(stoi(token));
        }
        stacks.push_back(stoi(s));
        int length = stacks.size(), cur_pos;
        for(int i=0;i<length;i++){
            if((cur_pos = findMax(stacks, length-i))!=length-i-1){
                // the max value is not on the right position -> Do flip
                if(cur_pos == 0){
                    // leftmost
                    flip(stacks, length-i);
                    cout<<i+1<<" ";
                    // cout<<"max Value at pos:"<<cur_pos<<endl;
                }
                else{
                    // cout<<"\n"<<length<<", "<<cur_pos<<"\n";
                    flip(stacks, cur_pos+1);
                    cout<<length-cur_pos<<" ";
                    flip(stacks, length-i);
                    cout<<i+1<<" ";
                }
                
            }
        }cout<<"0\n";
    }
    
    
    return 0;
}