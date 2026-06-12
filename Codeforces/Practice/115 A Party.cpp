#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int t = 1, n;
int a[2000];

int bfs(int x){

    queue< pair<int,int> > q;

    q.push({x,1});

    int ans = 0;
    while(!q.empty()){
        auto u = q.front(); q.pop();
        ans = max(ans, u.s);
        for(int i=0;i < n; i++)
            if(a[i] == u.f)
                q.push({i+1, u.s + 1});
    }
    return ans;
}

int solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int ans = 0;
    for(int i=0;i<n;i++)
        if(a[i] == -1)
            ans = max(ans, bfs(i+1));
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}

