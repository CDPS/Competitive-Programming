#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,m,l,x,y;
    cin >> t;

    while(t--){

        cin >> n >> m >> l;

        vector<pair<int,pair<int,int>>> a;
        for(int i=0;i<n;i++)
            cin >> x >> y, a.push_back({x,{y, 0}});
        for(int i=0;i<m;i++)
            cin >> x >> y, a.push_back({x,{y, 1}});

        sort(a.begin(), a.end());

        priority_queue<int> pq;

        int acc = 1, ans = 0;
        for(int i=0;i<n+m;i++){

            if(a[i].s.s == 1) { pq.push(a[i].s.f); continue; }

            x = a[i].f; y = a[i].s.f;
            while( y-x+2 > acc && !pq.empty())
                acc += pq.top(), pq.pop(), ans++;

            if(acc < y-x+2){ ans = -1; break; }
        }

        cout << ans << "\n";
    }
    return 0;
}
