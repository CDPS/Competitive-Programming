#include <bits/stdc++.h>

using namespace std;

int t =1, n,c;
int a[200000];

int solve(){

    cin >> n >> c;
    for(int i=0;i<n;i++) cin >> a[i];

    int ans  = 0;
    for(int i=0;i<n-1;i++)
        ans = max(ans, a[i]-c-a[i+1]);

    return ans ;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}


