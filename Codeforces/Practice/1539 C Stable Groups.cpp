#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll k , x;

int main(){

    cin >> n >> k >> x;

    vector<ll> a(n);

    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());

    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(int i=1;i<n;i++)
        if(a[i]-a[i-1] > x)
            pq.push((a[i]-a[i-1]-1)/x);

    while(!pq.empty() && k >= pq.top())
        k-= pq.top(), pq.pop();

    cout << pq.size() + 1<< "\n";

    return 0;
}

