#include<bits/stdc++.h>
using namespace std;
string ori_order[53] = {
    "Emtpy",
    "2 of Clubs",
    "3 of Clubs",
    "4 of Clubs",
    "5 of Clubs",
    "6 of Clubs",
    "7 of Clubs",
    "8 of Clubs",
    "9 of Clubs",
    "10 of Clubs",
    "Jack of Clubs",
    "Queen of Clubs",
    "King of Clubs",
    "Ace of Clubs",
    "2 of Diamonds",
    "3 of Diamonds",
    "4 of Diamonds",
    "5 of Diamonds",
    "6 of Diamonds",
    "7 of Diamonds",
    "8 of Diamonds",
    "9 of Diamonds",
    "10 of Diamonds",
    "Jack of Diamonds",
    "Queen of Diamonds",
    "King of Diamonds",
    "Ace of Diamonds",
    "2 of Hearts",
    "3 of Hearts",
    "4 of Hearts",
    "5 of Hearts",
    "6 of Hearts",
    "7 of Hearts",
    "8 of Hearts",
    "9 of Hearts",
    "10 of Hearts",
    "Jack of Hearts",
    "Queen of Hearts",
    "King of Hearts",
    "Ace of Hearts",
    "2 of Spades",
    "3 of Spades",
    "4 of Spades",
    "5 of Spades",
    "6 of Spades",
    "7 of Spades",
    "8 of Spades",
    "9 of Spades",
    "10 of Spades",
    "Jack of Spades",
    "Queen of Spades",
    "King of Spades",
    "Ace of Spades"
};
struct rule
{
    int pos;
    int moveTo;
};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        vector<vector<int> >poker;
        vector<int> deck;
        deck.resize(53);
        for(int i=1;i<=52;i++)deck[i] = i;
        int n;
        cin>>n;
        poker.resize(n+1);
        for(int i=1;i<=n;i++){
            poker[i].resize(53);
            int tmp;
            for(int j=1;j<=52;j++){
                // cin>>tmp;
                // if(tmp==j)continue;
                // rule r;
                // r.pos = j;
                // r.moveTo = tmp;
                // poker[i].push_back(r);
                cin>>poker[i][j];
            }
        }
        

        // for(int i=1;i<=n;++i){
        //     for(int j=1;j<=poker[i].size();++j){
        //         cout<<poker[i][j]<<" ";
        //     }cout<<endl;
        // }cout<<endl;
        
		// getchar();
        int shuffle_rule;
        string str;getline(cin,str);
        while (getline(cin,str) ) {
            // cout<<"str:"<<str<<endl;
            if(str.empty())break;
            stringstream ss;  
            ss << str;  
            ss >> shuffle_rule; 
			// shuffle_rule = stoi(str);
            // cin>>shuffle_rule;
            int tmp[53];
            for(int j=1;j<53;j++){
                tmp[j] = deck[poker[shuffle_rule][j]];
            }
            for(int j=1;j<53;j++){
                deck[j] = tmp[j];
            }
        }
        // for(int i=0;i<n;i++){
            
        // }
        for(int i=1;i<=52;++i){
            // cout<<deck[i]<<" ";
            cout<<ori_order[deck[i]]<<"\n";
        }
        cout<<endl;
    }
    
    return 0;
}