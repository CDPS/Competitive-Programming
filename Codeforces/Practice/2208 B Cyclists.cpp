#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define node pair<int,int>

int t, n, k, p, m, x;

struct CustomCompare {
    bool operator()(const node& a, const node & b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

int solve(){

    cin >> n >> k >> p >> m;

    priority_queue<node, vector<node>, CustomCompare> pq;
    for(int i=1;i<=k;i++)
        cin >> x, pq.push({x, i== p});

    queue<node> q;
    for(int i=k + 1; i<=n;i++)
        cin >> x, q.push({x, i== p});

    int ans = 0;
    while(m >= pq.top().f ){

        auto curr = pq.top(); pq.pop();
        ans+= curr.s;
        m-= curr.f;

        q.push(curr);
        pq.push(q.front());
        q.pop();
    }

    return ans;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
