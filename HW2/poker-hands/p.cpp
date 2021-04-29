#include<bits/stdc++.h>
using namespace std;

int value( char ch )
{
	if ( ch == 'T' ) return 8;
	if ( ch == 'J' ) return 9;
	if ( ch == 'Q' ) return 10;
	if ( ch == 'K' ) return 11;
	if ( ch == 'A' ) return 12;
	return ch - '2';
}
 
int color( char ch )
{
	if ( ch == 'S' ) return 0;
	if ( ch == 'H' ) return 1;
	if ( ch == 'D' ) return 2;
	if ( ch == 'C' ) return 3;
    else return -1;
}

int get_rank(vector<vector<int> >v){
    // straight flush
    for(int i=0;i<4;++i){
        for(int j=0;j<9;++j){
            if(v[i][j]&&v[i][j+1]&&v[i][j+2]&&v[i][j+3]&&v[i][j+4]){
                return 13*13*13*13*13+40+j;
            }
        }
    }
    // four of a kind
    for(int j=0;j<13;j++)
        if(v[4][j]>=4)
            return 13*13*13*13*13+20+j;
    // full house
    int three = 0,two = 0;
	for (int i = 12; i >= 0; -- i) {
		if (v[4][i] == 2)
			two = two*15+i+1;
		if (v[4][i] == 3)
			three = i+1;
	}
	if (two && three) return 13*13*13*13*13+three+1;
    //flush
	for (int i = 0; i < 4; ++ i) {
		int count = 0, number = 0;
		for (int j = 12; j >= 0; -- j) 
			for (int k = 0; k < v[i][j]; ++ k) {
				++ count;
				number = number*13+j;
			}
		if (count == 5) return number;
	}
	//straight
	for (int i = 0; i < 9; ++ i)
		if (v[4][i]&v[4][i+1]&v[4][i+2]&v[4][i+3]&v[4][i+4]) 
			return i-20;
	//three-of-a-kind
	if (three) return three-40;
	
	int ans = 0;
	for (int i = 12; i >= 0; -- i)
		if (v[4][i] == 1)
			ans = ans*13+i;
	//two-pairs
	if (two >= 15) two*15+ans-8000;
	//one-pair
	if (two) return two*13*13*13+ans-13*13*13*13*30;
	//high-card
    return ans-13*13*13*13*50;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    string s;
    while(getline(cin,s)){
        if(s=="")break;
        string delim = " ";
            
        int white_rank,black_rank;
        vector<vector<int> > white,black;
        white.clear();
        black.clear();
        white.resize(5);
        black.resize(5);
        for(int i=0;i<5;++i)white[i].resize(13);
        for(int i=0;i<5;++i)black[i].resize(13);
        // 2->[0] , A->[12]
        int pos;
        /* Parse Input */
        for(int i=0;i<5;i++){
            pos = s.find(delim);
            string tmp = s.substr(0,pos);
            black[color(tmp[1])][value(tmp[0])]++;
            black[4][value(tmp[0])]++;
            s.erase(0,pos+delim.length());
        }
        for(int i=0;i<4;i++){
            pos = s.find(delim);
            string tmp = s.substr(0,pos);
            white[color(tmp[1])][value(tmp[0])]++;
            white[4][value(tmp[0])]++;
            s.erase(0,pos+delim.length());
        }
        white[color(s[1])][value(s[0])]++;
        white[4][value(s[0])]++;
        // /* Test Parse */
        // cout<<"Black:\n";
        // for(int i=0;i<5;++i){
        //     for(int j=0;j<13;j++)
        //         cout<<black[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<"White:\n";
        // for(int i=0;i<5;++i){
        //     for(int j=0;j<13;j++)
        //         cout<<black[i][j]<<" ";
        //     cout<<endl;
        // }
        /* Dual */
        white_rank = get_rank(white);
        black_rank = get_rank(black);
        if(white_rank > black_rank)cout<<"White wins.\n";
        else if(white_rank < black_rank)cout<<"Black wins.\n";
        else cout<<"Tie.\n";
    }
    
    return 0;
}