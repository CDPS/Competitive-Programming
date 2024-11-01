#include <bits/stdc++.h>

using namespace std;

struct node{
    int p,a, i;
    string n;
    node(int p,int a,int i,string n): p(p),a(a),i(i), n(n){}
    bool operator < (const node &x) const{
        if(a==x.a)
            return i > x.i;
        return a > x.a;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t,n,k,x;
    string s;
    cin >> t;

    while(t--){

        cin >> n >> k;
        priority_queue<node> pq;
        for(int i=0;i<n;i++)
            cin >> s >> x, pq.push(node(x, x, i, s));

        while(k--){
           node u = pq.top();
           pq.pop();
           pq.push(node(u.p, u.a + u.p, u.i, u.n));
           cout << u.a << " " << u.n << "\n";
        }
    }
    return 0;
}

