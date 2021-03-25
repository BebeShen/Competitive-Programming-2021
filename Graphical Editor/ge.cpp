#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<char> >table;
void dfs(int x, int y, char now, char c)
{
	if (y < 0 || y >= n || x < 0 || x >= m || table[y][x] != now) return;
	table[y][x] = c;
	dfs(x + 1, y, now, c);
	dfs(x - 1, y, now, c);
	dfs(x, y + 1, now, c);
	dfs(x, y - 1, now, c);
}

int main(){
    char commands;
    while (cin>>commands)
    {
        if(commands=='X'){
            break;
        }
        else if(commands=='I'){
            // create table
            cin>>m>>n;
            table.resize(n);
            for(int i=0;i<n;i++)
                table[i].resize(m);
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    table[i][j] = 'O';
                }
            }
        }   
        else if(commands=='C'){
            // clear table
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    table[i][j] = 'O';
                }
            }
        }
        else if(commands=='L'){
            int x,y;
            // y:row, x:col
            char color;
            cin>>x>>y>>color;
            // column [X][Y] = color
            table[y-1][x-1] = color;
        }
        else if(commands=='V'){
            int x,y1,y2;
            char color;
            cin>>x>>y1>>y2>>color;
            if(y1>y2){
                int tmp = y2;
                y2 = y1;
                y1 = tmp;
            }
            for(int i=y1-1;i<=y2-1;i++){
                table[i][x-1] = color;
            }
        }
        else if(commands=='H'){
            int x1,x2,y;
            char color;
            cin>>x1>>x2>>y>>color;
            if(x1>x2){
                int tmp = x2;
                x2 = x1;
                x1 = tmp;
            }
            
            for(int i=x1-1;i<=x2-1;i++){
                table[y-1][i] = color;
            }
        }
        else if(commands=='K'){
            int x1,x2,y1,y2;
            char color;
            cin>>x1>>y1>>x2>>y2>>color;
            if(x1>x2){
                int tmp = x2;
                x2 = x1;
                x1 = tmp;
            }
            if(y1>y2){
                int tmp = y2;
                y2 = y1;
                y1 = tmp;
            }
            for(int i=x1-1;i<=x2-1;i++){
                for(int j=y1-1;j<=y2-1;j++){
                     table[j][i] = color;
                }
            }
        }
        else if(commands=='F'){
            // region whose color is the same as [y][x]
            int x,y;
            char color;
            cin>>x>>y>>color;
            char _ch = table[y-1][x-1];
            if (_ch != color) dfs(x-1, y-1, _ch, color);
        }
        else if(commands=='S'){
            // write table into file
            string file_name;
            cin>>file_name;
            cout<<file_name<<"\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<table[i][j];
                }cout<<"\n";
            }
        }else{
            continue;
        }
    }
    
    
    return 0;
}