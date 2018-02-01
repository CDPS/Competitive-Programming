#include <bits/stdc++.h>

using namespace std;

struct node{
    string s;
    node(string a): s(a){}
    bool operator < (const node  &a)const{
        if(s.size()==a.s.size())
            return s < a.s;
        return s.size() < a.s.size();
    }
};

map<string,int> mp;
void bfs(){

    queue<string> q; vector<node> v;
    for(string  i = "a";i<="z";)
        q.push(i),v.push_back(node( i) ),i[0]++;

    while(!q.empty()){

        string u = q.front(); q.pop();

        if(u.size()==5) continue;

        char last = u[u.size()-1] +1;
        for(;last <='z';last++){
            string vx = u + last; v.push_back(vx); q.push(vx);
        }
    }

    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) mp[v[i].s] = i+1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    bfs();
    string s;
    while(cin >> s){
        int ans = (mp.find(s)!=mp.end())? mp[s] : 0;
        cout <<  ans  << "\n";
    }
    return 0;
}
