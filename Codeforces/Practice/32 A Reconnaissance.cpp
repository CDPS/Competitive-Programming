#include <bits/stdc++.h>

using namespace std;

int t = 1, n, k;
int a[1000];

int solve(){

    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a+ n);

    int ans = 0;
    for(int i =0 ; i< n; i++){
        auto it1 = lower_bound(a, a + n, a[i]-k);
        auto it2 = upper_bound(a, a + n, a[i]+k);
        ans+= (it2-it1)-1;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}


