#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int oo = 1e9;
int t = 1, n;
int a[1000];

ll solve(){

    cin >> n;

    int first = oo, last = -oo;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i])
            first = min(i, first), last  = max(i, last);
    }

    if(first == oo)  return 0;
    if(first == last)return 1;

    ll ans = 1;
    for(int i=first, zero_count = 0; i <= last; i++){
        if(a[i]){
            ans*= zero_count +1;
            zero_count = 0;
            continue;
        }
        zero_count++;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
