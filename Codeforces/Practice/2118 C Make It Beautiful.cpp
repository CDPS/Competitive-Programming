#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[5000];
ll k;

ll getLS(ll x){
    for(int i=0;i<=60;i++)
        if((x&(1ll<<i))==0) return (1ll<<i);
    return (1ll<<61);
}

struct node{
    ll x,  n;
    node(ll x, ll n): x(x),n(n){}
    bool operator < (const node &a) const {
        return x > a.x;
    }
};

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    ll num;
    int t, n;
    cin >> t;

    while(t--){

        cin >> n >> k;

        priority_queue<node> pq;
        for(int i=0;i<n;i++) {
            cin >> num;
            pq.push(node(getLS(num),num));
        }

        while(k >= pq.top().x){
            node u = pq.top(); pq.pop();
            ll nn = u.n | u.x;
            k-= (nn - u.n);
            pq.push(node( getLS(nn), nn) );
        }

        int ans = 0;
        while(!pq.empty())
            ans+=__builtin_popcountll(pq.top().n), pq.pop();

        cout << ans << "\n";
    }
    return 0;
}
