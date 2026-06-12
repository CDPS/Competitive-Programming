#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int t = 1, n, x;

string op;

void solve(){

    cin >> n;

    vector< pair<string, int > > v;
    priority_queue< int, vector<int>, greater<int> > pq;

    for(int i=0; i < n; i++){
        cin >> op;
        if(op[0] != 'r')
            cin >> x;
        v.push_back({op, x});
    }

    vector< pair<string, int > > ans;
    for(int i=0;i < n; i++ ){

        if(v[i].f[0] == 'r' && pq.empty() ){
            ans.push_back({"insert", 1});
            pq.push(v[i].s);
        }
        else if(v[i].f[0] == 'g' && pq.empty() ){
           ans.push_back({"insert", v[i].s});
           pq.push(v[i].s);
        }
        else if(v[i].f[0] == 'g' && pq.top() > v[i].s ){
           ans.push_back({"insert", v[i].s});
           pq.push(v[i].s);
        }
        else if(v[i].f[0] == 'g' && pq.top() < v[i].s ){

           while(!pq.empty() && pq.top() < v[i].s )
                pq.pop(), ans.push_back({"removeMin", 0});

           if(pq.empty() || pq.top() > v[i].s)
             ans.push_back({"insert", v[i].s}), pq.push(v[i].s);
        }

        if(v[i].f[0] == 'i')
             pq.push(v[i].s);

        if(v[i].f[0] == 'r')
             pq.pop();

        ans.push_back(v[i]);
    }

    cout << ans.size() << "\n";
    for(int i=0; i < ans.size(); i++){
        if(ans[i].f[0] == 'r')
            cout << ans[i].f << "\n";
        else
            cout  << ans[i].f << " " << ans[i].s << "\n";
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
