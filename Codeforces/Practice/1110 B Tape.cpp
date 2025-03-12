#include <bits/stdc++.h>

using namespace std;

const int oo = 2e9;

int a[100001];

int main(){

    int n, m, k;
    cin >> n >> m >> k;

    for(int i=0;i<n;i++) cin >> a[i];
    a[n] = 2*m+1;


    priority_queue<int> pq;
    for(int i=1;i<=n;i++)
        pq.push(a[i]-a[i-1]+1);

    int q = (n-k);
    cout << "<----Eliminados------>" << "\n";
    while(q--)
        cout << pq.top<< "\n", pq.pop();

    int ans = 0;
    while(!pq.empty())
        ans+= pq.top(), pq.pop();

    cout << ans << "\n";
    return 0;
}
