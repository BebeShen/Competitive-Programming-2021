#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int s;
    int test_case = 1;
    while(cin>>s){
        vector<bool>schedule_empty(481,true);
        schedule_empty[480] = false;
        for(int i=0;i<s;++i){
            int h1,h2,m1,m2;
            char skip;
            string s;
            cin>>h1>>skip>>m1>>h2>>skip>>m2;
            getline(cin,s);
            for(int j=(h1-10)*60 + m1;j<(h2-10)*60 + m2;++j){
                schedule_empty[j] = false;
            }
        }
        int tcount, max_period = -1, max_start;
        if(schedule_empty[0])tcount = 1;
        else tcount = 0;
        for(int i=1;i<481;++i){
            if(schedule_empty[i-1]&&schedule_empty[i])tcount++;
            if((!schedule_empty[i-1]) && schedule_empty[i])tcount=1;
            if(schedule_empty[i-1]&& (!schedule_empty[i])){
                if(max_period < tcount){
                    max_period = tcount;
                    max_start = i - max_period;
                }
            }
        }
        cout<<"Day #"<<test_case++<<": the longest nap starts at "<<10 + max_start/60<<":"<<setw(2) << setfill('0')<<max_start%60<<" and will last for ";
        if(max_period>=60)
            cout<<to_string(max_period/60)<<" hours and " << to_string(max_period%60) << " minutes.\n";
        else
            cout<<to_string(max_period%60) << " minutes.\n";
    }
    return 0;
}