#include <bits/stdc++.h>

using namespace std;

int oo = 10000;
int n, m;

int main(){

    cin >> n >> m;

    if(m <= n){
        cout << n-m << "\n";
        return 0;
    }

    queue<pair<int,int>> q; q.push({n, 0});

    set<int> visit;
    while(!q.empty()){

        auto u = q.front(); q.pop();

        if(visit.count(u.first)) continue;

        visit.insert(u.first);

        if(u.first == m){
            cout << u.second << "\n";
            break;
        }

        if(u.first > oo) continue;
        if(u.first < 0) continue;

        q.push({u.first*2, u.second + 1});
        q.push({u.first-1, u.second + 1});
    }
    return 0;
}
