#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
int a[27];
string s;

ll solve(){

    cin >> n >> k >> s;

    for(int i=0;i<n;i++)
        a[ s[i]- 'A']++;

    sort(a ,  a + 27);

    ll ans = 0;
    for(int i=26;i>=0 && k > 0;i--){
        if(k >= a[i] )
            ans += 1ll*a[i]*a[i], k-=a[i];
        else
            ans += 1ll*k*k, k = 0;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cout <<  solve() << "\n";

    return 0;
}
