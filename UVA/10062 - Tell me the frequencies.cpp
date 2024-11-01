#include <bits/stdc++.h>

using namespace std;

struct node{
    int c, acc;
    node(int c, int acc) : c(c), acc(acc){}
    bool operator < (const node &a) const{
        if(acc == a.acc)
            return c < a.c;
        return acc > a.acc;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    string s;
    bool first =true;
    while(getline(cin, s)){

        map<char, int> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;

        priority_queue<node> pq;
        for(auto it = mp.begin(); it != mp.end();it++)
            pq.push(node(it->first, it->second));

        if(!first) cout << "\n";
        first = false;

        while(!pq.empty())
            cout << pq.top().c << " " << pq.top().acc << "\n", pq.pop();
    }
    return 0;
}
