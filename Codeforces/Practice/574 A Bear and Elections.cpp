#include <bits/stdc++.h>

using namespace std;

int t = 1, n, x, me;
int a[1000];

int solve(){

    cin >> n >> me;

    priority_queue<int> pq;
    for(int i=0; i < n-1; i++)
        cin >> x , pq.push(x);

    int ans = 0;
    while( me <= pq.top()){
        int curr = pq.top(); pq.pop();
        me++, pq.push(curr - 1);
        ans++;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
