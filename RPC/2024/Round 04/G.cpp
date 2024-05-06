#include <bits/stdc++.h>

using namespace std;

map<string, long> mp;

struct node{
    string n;
    long s;
    node(string n, long s) : n(n), s(s){}
    bool operator < (const node &a) const{
        if(s == a.s) return n > a.n;
        return s < a.s;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    long n,q,x;
    string s;
    priority_queue<node> pq;
    cin >> n >> q;

    while(n--){
        cin >> s >> x;
        pq.push(node(s,x));
        mp[s] = x;
    }

    long op;
    while(q--){
        cin >> op;
        if(op == 1){
            cin >> s >> x;
            mp[s] += x;
            pq.push(node(s,mp[s]));
        }else{
            while(!pq.empty()){
                node u = pq.top();
                pq.pop();
                if(u.s == mp[u.n]){
                    cout << u.n << " " << u.s << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
