#include<bits/stdc++.h>
using namespace std;

int n, m;
bool comp(int i, int j) {
    if(i%m != j%m) {
        // 兩數除以 M 的餘數不相等
        return i%m < j%m;
    }

    if(i&1 && j&1) return i>j;                  // 兩奇數除以 M 餘數大小相等，原本數值較大的奇數排在前面
    else if(!(i&1) && !(j&1)) return i<j;       // 兩偶數除以 M 餘數大小相等，較小的偶數排在前面
    else return i&1;                            // 一奇一偶除以 M 餘數大小相等，奇數要在偶數前面
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (cin>>n>>m) {
        if(n==0 && m==0)break;
        cout<<n<<" "<<m<<"\n";
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums.begin(), nums.end(), comp);
        for(int i=0;i<n;i++){
            cout<<nums[i]<<"\n";
        }
    }
    cout<<"0 0"<<endl;
    return 0;
}