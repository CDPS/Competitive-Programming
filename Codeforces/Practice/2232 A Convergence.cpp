#include <bits/stdc++.h>

using namespace std;

int t, n;

int a[100];

int solve(){

    cin >> n;

    for(int i=0; i < n; i++) cin >> a[i];
    sort(a , a + n);

    int ans = 1e9;
    for(int i= 0; i< n; i++){
        int L = 0, R = 0;
        for(int j =0; j < i; j++)
            L+= a[j] < a[i];
        for(int j = n-1; j > i; j--)
            R+= a[j] > a[i];
        ans = min(ans, max(L, R));
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