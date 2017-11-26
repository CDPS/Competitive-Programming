#include <bits/stdc++.h>

using namespace std;

struct node{
    string s,t;

    node(string a){
        s = t = a;
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        sort(t.begin(),t.end());
    }

    bool operator < (const node &a) const{ return  s < a.s; }
};

map<string,int> mp;
vector<node> v;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    stringstream ss;
    string line,word;

    while(getline(cin,line)){

        if(line=="#") break;
        ss.clear(); ss << line;

        while(ss >> word){
            node x = node(word);
            v.push_back(x);
            mp[x.t]++;
        }
    }

    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        if( mp[v[i].t ]==1 )
            cout << v[i].s << "\n";
    }
    return 0;
}
