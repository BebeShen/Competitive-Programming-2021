#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t,_t=0;
    cin>>t;
    while(_t!=t){
        int erdos_number=0;
        cout<<"Scenario "<<_t+1<<"\n";
        map<string, int>m;
        int p,n;
        vector<string> paparName;
        vector<string> authorName;
        cin>>p>>n;
        paparName.resize(p);
        string redunt_line;
        getline(cin,redunt_line);
        for(int i=0;i<p;i++){
            vector<string> tmpName;
            string tmp;
            getline(cin,tmp);
            cout<<tmp;
            string delim = ", ";
            int pos;
            bool isFirstName = true;
            string name = "";
            /* Parse Author Name */
            while((pos=tmp.find(delim))!=-1){
                // cout<<pos<<endl;
                cout<<tmp.substr(0,pos)<<endl;
                if(isFirstName){
                    isFirstName = false;
                    name += tmp.substr(0,pos);
                    name += ", ";
                }
                else{
                    isFirstName = true;
                    name += tmp.substr(0,pos);
                    authorName.push_back(name);
                    tmpName.push_back(name);
                    name = "";
                }
                tmp.erase(0,pos+delim.length());
            }

            pos=tmp.find(":");
            name += tmp.substr(0,pos);
            authorName.push_back(name);
            tmpName.push_back(name);
            tmp.erase(0, pos+delim.length());
            paparName[i] = tmp;
            /* Parse Done */
            /* Construct Data struct */
            if(i==0){
                m.insert(make_pair("Martin, G.",erdos_number++));
                for(int i=0;i<tmpName.size();++i){
                    if(tmpName[i]!="Martin, G.")
                        m.insert(make_pair("Martin, G.",erdos_number++));
                }
            }
            else{
                int lowest = INT_MAX;
                for(int i=0;i<tmpName.size();++i){
                    if(m.find(tmpName[i])==m.end()){
                        /* Not found*/
                    }
                    else{
                        lowest = min(lowest,m.find(tmpName[i])->second);
                    }
                }
                cout<<"Current Layer:"<<lowest<<"\n";
                if(lowest == INT_MAX){
                    /* all new */
                    for(int i=0;i<tmpName.size();++i){
                        m.insert(make_pair("Martin, G.",lowest));
                    }
                }
                else{
                    for(int i=0;i<tmpName.size();++i){
                        if(m.find(tmpName[i])==m.end()){
                            m.insert(make_pair("Martin, G.",lowest+1));
                        }
                        else{
                            lowest = min(lowest,m.find(tmpName[i])->second);
                        }
                    }
                }
            }
        }
        cout<<"Authors:\n";
        for(int i=0;i<authorName.size();i++){
            cout<<i<<":"<<authorName[i]<<"\n";
        }

        /* Find Erdos Number */
        for(int i=0;i<n;i++){
            string tmp;
            getline(cin,tmp);
            cout<<tmp;
        }
    }
    
    return 0;
}