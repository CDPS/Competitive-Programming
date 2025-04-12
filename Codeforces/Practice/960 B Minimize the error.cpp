#include <bits/stdc++.h>

using namespace std;

int a[1000];

int main(){

    int n, k1, k2, k, x;
    cin >> n >> k1 >> k2;
    k = k1+ k2;

    priority_queue<int> pq;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        cin >> x;
        if(abs(a[i]-x) > 0 )
            pq.push(abs(a[i]-x));
    }

    while(k && !pq.empty()){
        x = pq.top(); pq.pop();
        if(x-1 > 0)
            pq.push(x-1);
        k--;
    }

    long long ans = k%2;
    while(!pq.empty())
        ans +=(1ll*pq.top()*pq.top()), pq.pop();

    cout << ans << "\n";

    return 0;
}
