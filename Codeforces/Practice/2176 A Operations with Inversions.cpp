#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[100];

int solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int ans=0;
    priority_queue<int> pq; pq.push(a[0]);
    for(int i=1;i<n;i++){
        if(pq.top() > a[i])
            ans++;
        pq.push(a[i]);
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
