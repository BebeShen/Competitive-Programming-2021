#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string a,b;
    while(getline(cin,a)){
        getline(cin,b); 
        if(cin.eof())break;
		// sort( a.begin(), a.end());
		// sort( b.begin(), b.end());
		// for ( int i = 0,j = 0 ; i < a.length() && j < b.length(); ) {
		// 	if(a[i]==' ' || a[i]>='A' && a[i]<='Z') i++;
		// 	if(b[j]==' ' || b[j]>='A' && b[j]<='Z') j++; //移除空格或者是大写字母
		// 	if(a[i]==b[j])
		// 	{
		// 		cout<<a[i];
		// 		i++;
		// 		j++;
		// 	}
		// 	if(a[i]<b[j]) i++;
		// 	if(a[i]>b[j]) j++;
		// }
        int a_count[27];
        int b_count[27];
        int com[27];
        memset(a_count,0,sizeof(a_count));
        memset(b_count,0,sizeof(b_count));
        memset(com,0,sizeof(com));
        for(int i=0;i<a.length();++i){
            // cout<<a[i]<<" "<<a[i]-'a'<<endl;
            a_count[a[i]-'a']++;
        }
        for(int i=0;i<b.length();++i){
            b_count[b[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            com[i] = min(a_count[i],b_count[i]);
            if(com[i]>0)
                for(int j=0;j<com[i];++j)
                    cout<<char('a'+i);
            
        }
        
        cout<<'\n';
    }
    return 0;
}