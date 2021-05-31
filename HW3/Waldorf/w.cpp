#include<bits/stdc++.h>
using namespace std;

int x,y;
int m,n;

int find(string s, vector<vector<char> >grid){
    // bool f = false;
    int l = s.length();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[0] == grid[i][j]){
                // cout<<"s[0] match:"<<i<<", "<<j<<endl;
                bool equal = false;
                if(i-l>=0 && !equal){
                    // Up
                    for(int z=0;z<l;z++){
                        if(s[z]!=grid[i-z][j])break;
                        if(s[z]==grid[i-z][j] && z==l-1)
                            equal = true;
                    }
                    if(equal){
                        x = i;
                        y = j;
                        return 1;
                    }
                    if(j-l>=0 && !equal){
                        // Up Left
                        for(int z=0;z<l;z++){
                            if(s[z]!=grid[i-z][j-z])break;
                            if(s[z]==grid[i-z][j-z] && z==l-1)
                                equal = true;
                        }
                    }
                    if(equal){
                        x = i;
                        y = j;
                        return 1;
                    }
                    if(j+l-1<=n && !equal){
                        // Up Right
                        for(int z=0;z<l;z++){
                            if(s[z]!=grid[i-z][j+z])break;
                            if(s[z]==grid[i-z][j+z] && z==l-1)
                                equal = true;
                        } 
                    }
                    if(equal){
                        x = i;
                        y = j;
                        return 1;
                    }
                }
                if(i+l-1<=m && !equal){
                    // Down
                    for(int z=0;z<l;z++){
                        if(s[z]!=grid[i+z][j])break;
                        if(s[z]==grid[i+z][j] && z==l-1)
                            equal = true;
                    }
                    if(equal){
                        x = i;
                        y = j;
                        return 1;
                    }
                    if(j-l>=0 && !equal){
                        // Down Left
                        for(int z=0;z<l;z++){
                            if(s[z]!=grid[i+z][j-z])break;
                            if(s[z]==grid[i+z][j-z] && z==l-1)
                                equal = true;
                        }
                    }
                    if(equal){
                        x = i;
                        y = j;
                        return 1;
                    }
                    if(j+l-1<=n && !equal){
                        // Down Right
                        // cout<<i+l<<","<<j+l<<endl;
                        for(int z=0;z<l;z++){
                            if(s[z]!=grid[i+z][j+z])break;
                            if(s[z]==grid[i+z][j+z] && z==l-1)
                                equal = true;
                        } 
                    }
                    if(equal){
                        x = i;
                        y = j;
                        return 1;
                    }
                }
                if(j-l>=0 && !equal){
                    // Left
                    for(int z=0;z<l;z++){
                        if(s[z]!=grid[i][j-z])break;
                        if(s[z]==grid[i][j-z] && z==l-1)
                            equal = true;
                    }
                }
                if(equal){
                    x = i;
                    y = j;
                    return 1;
                }
                if(j+l-1<=n && !equal){
                    // Right
                    for(int z=0;z<l;z++){
                        if(s[z]!=grid[i][j+z])break;
                        if(s[z]==grid[i][j+z] && z==l-1)
                            equal = true;
                    }
                }
                if(equal){
                    x = i;
                    y = j;
                    return 1;
                }
            
            }
        }
    }
    // cout<<"No match\n";
    return -1;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin>>t;
    while (t--){
        cin>>m>>n;
        vector<vector<char> >grid;
        grid.resize(m+1);
        for(int i=0;i<m+1;i++)grid[i].resize(n+1);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                char tmp;
                cin>>tmp;
                // store as lowercase letters
                grid[i][j] = tolower(tmp);
            }
        }
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         cout<<grid[i][j]<<" ";
        //     }cout<<endl;
        // }
        int k;
        cin>>k;
        for(int i=0;i<k;i++){
            string sl;
            cin>>sl;
            transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
            // cout<<sl<<endl;
            find(sl, grid);
            cout<<x<<" "<<y<<"\n";
        }
        cout<<"\n";
    }
    
    return 0;
}