#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    while(cin>>n){
        queue<int> q;
        stack<int> s;
        priority_queue<int> p;
        vector<int> ans;
        bool is_q = true;
        bool is_s = true;
        bool is_p = true;
        for(int i=0;i<n;i++){
            int command;
            int num;
            cin>>command;
            if(command == 1){
                cin>>num;
                s.push(num);
                q.push(num);
                p.push(num);
            }
            else if(command == 2){
                cin>>num;
                if(num != s.top())is_s = false;
                s.pop();
                if(num != q.front())is_q = false;
                q.pop();
                if(num != p.top()) is_p = false;
                p.pop();
            }
        }
        if((is_s && is_p)||(is_q && is_p)||(is_s && is_q)){
            cout<<"not sure\n";
        }
        else if(is_s){
            cout<<"stack\n";
        }
        else if(is_p){
            cout<<"priority queue\n";
        }
        else if(is_q){
            cout<<"queue\n";
        }
        else{
            cout<<"impossible\n";
        }
    }
    
    return 0;
}