#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int a[300001];

ll solve(){

    cin >> n;

    ll sum = 0;
    for(int i=1;i<=n;i++)
        cin >> a[i], sum+= a[i];

    sort(a, a + n + 1);

    ll curr = 0, ans = 0;
    for(int i=1;i<=n-1;i++){
        curr += a[i-1];
        ans+= sum - curr;
    }
    return ans + sum;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cout <<  solve() << "\n";

    return 0;
}
