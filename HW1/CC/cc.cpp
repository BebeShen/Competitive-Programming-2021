#include<bits/stdc++.h>
using namespace std;
struct pos
{
    int x;
    int y;
};
//TODO: 沒有檢查中間有沒有人
// upper -> white
// lower -> black
pos k,K;
bool checkRook(vector<pos>r,pos k){
    for(int i=0;i<r.size();i++){
        cout<<r[i].x<<" ,"<<r[i].y<<endl;
        if(r[i].x==k.x || r[i].y==k.y)return true;//check
    }
    return false;
}


bool checkBishop(vector<pos>b,pos k){
    for(int i=0;i<b.size();i++){
        if(abs(b[i].x-k.x)/abs(b[i].y-k.y))return true;//check
    }
    return false;
}

bool checkQueen(vector<pos>q,pos k){
    for(int i=0;i<q.size();i++){
        if(q[i].x==k.x || q[i].y==k.y || abs(q[i].x-k.x)/abs(q[i].y-k.y))return true;//check
    }
    return false;
}

bool checkKnight(vector<pos> n,pos k){
    for(int i=0;i<n.size();++i){
        if(abs(n[i].x-k.x)==2 && abs(n[i].y-k.y)==1)return true;
        if(abs(n[i].x-k.x)==1 && abs(n[i].y-k.y)==2)return true;
    }
    return false;
}

bool checkKing(pos k_other,pos k){
    if(abs(k_other.x - k.x)<=1 && abs(k_other.y - k.y)<=1)return true;
    return false;
}

bool checkPawn_bk(vector<pos>p, pos k){
    // white pawn
    for(int i=0;i<p.size();++i){
        if(abs(p[i].x - k.x)==1 && k.y==p[i].y-1)return true;
    }
    return false;
}

bool checkPawn_wk(vector<pos>p,pos k){
    // black pawn
    for(int i=0;i<p.size();i++){
        if(abs(p[i].x - k.x)==1 && k.y==p[i].y+1)return true;
    }
    return false;
}

bool checkBlack(vector<pos>p,vector<pos>n,vector<pos>b,vector<pos>r,vector<pos>q,pos whitek){
    return checkRook(r,k) && checkBishop(b,k) && checkQueen(q,k) && checkKnight(n,k) && checkKing(whitek,k) && checkPawn_bk(p,k);
}
bool checkWhite(vector<pos>p,vector<pos>n,vector<pos>b,vector<pos>r,vector<pos>q,pos blackk){
    return checkRook(r,K) && checkBishop(b,K) && checkQueen(q,K) && checkKnight(n,K) && checkKing(blackk,K) && checkPawn_wk(p,K);
}
vector<vector<char> >board;
        

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int round = 1;
    while(1){
        vector<pos>p,P;
        vector<pos>n,N;
        vector<pos>b,B;
        vector<pos>r,R;
        vector<pos>q,Q;
        board.resize(8);
        for(int i=0;i<8;i++)board[i].resize(8);
        bool flag = true; // for break while
        char ch;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>ch;
                if(ch!='.'){
                    board[i][j] = ch;
                    flag=false;
                    pos tmp;
                    tmp.x = i;
                    tmp.y = j;
                    if(ch=='p')q.push_back(tmp);
                    if(ch=='P')P.push_back(tmp);
                    if(ch=='n')n.push_back(tmp);
                    if(ch=='N')N.push_back(tmp);
                    if(ch=='b')b.push_back(tmp);
                    if(ch=='B')B.push_back(tmp);
                    if(ch=='r')r.push_back(tmp);
                    if(ch=='R')R.push_back(tmp);
                    if(ch=='q')q.push_back(tmp);
                    if(ch=='Q')Q.push_back(tmp);
                }
            }
        }
        if(flag)break;
        cout<<"Game #"<<round++<<": ";
        if(checkBlack(p,n,b,r,q,K))cout<<"black king is in check.\n";
        else if(checkWhite(P,N,B,R,Q,k))cout<<"white king is in check.\n";
        else cout<<"no king is in check.\n";
    }
    return 0;
}