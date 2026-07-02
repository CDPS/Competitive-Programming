#include <bits/stdc++.h>

using namespace std;

int t, n;

int a[6005];
bool vis[6005];
bool check[6005][6005];

int solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            check[i][j] = false;
        
    for (int i = 1; i <= n; i++) {
        int min_v = a[i];
        int max_v = a[i];
        
        for (int j = 1; j <= n; j++) vis[j] = false;
        
        for (int j = i; j <= n; j++) {
            if (vis[a[j]]) break;
            
            vis[a[j]] = true;
            min_v = min(min_v, a[j]);
            max_v = max(max_v, a[j]);
      
            if (max_v - min_v == j - i) 
                check[min_v][max_v] = true;
        }
    }

    int ans = 0;
    for (int L = 1; L <= n; L++) {
        for (int R = L; R <= n ; R++) {
            int M = (R - L) + R + 1; 
            if(M <= n && check[L][R] && check[R+1][M]) {
                ans = max(ans, R - L + 1);
            }
        }
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