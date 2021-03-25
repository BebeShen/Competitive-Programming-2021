#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, numHigh, numLow;
    vector<double>stu;
    double average,ans1,ans2;
    while(cin>>n){
        if(n==0)break;
        stu.resize(n);
        average = 0;
        for(int i=0;i<n;i++){
            cin>>stu[i];
            average += stu[i];    
        };
        average = average/n;
        cout<<"After / Average:"<<average<<endl;
        ans1 = ans2 = 0;
        for(int i=0;i<n;++i){
            double v = (long) (abs(stu[i] - average) * 100.0) / 100.0;
            if(stu[i]>average)ans1 += v;
            else ans2 += v;
        }
        cout<<ans1<<" "<<ans2<<endl;
        if(ans1>ans2)cout<<"$"<< fixed  <<  setprecision(2) << ans2 <<"\n";
        else cout<<"$"<< fixed  <<  setprecision(2) << ans1 <<"\n";
    }
    
    return 0;
}