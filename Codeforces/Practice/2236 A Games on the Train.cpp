#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[5];

int solve(){

    cin >> n;

    int maxi = -1;
    for(int i=0; i < n; i++)
        cin >> a[i], maxi = max(a[i], maxi);
    
    int ans = -1;
    for(int i=0; i < n; i++)
        ans = max(ans, maxi + 1 - a[i]);
    
    return ans;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
       cout << solve() << "\n";
    
    return 0;
}