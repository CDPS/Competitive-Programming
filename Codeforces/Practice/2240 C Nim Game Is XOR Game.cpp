#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[1000000];

int solve(){

    cin >> n;
    
    int X  = 0;
    for(int i=0; i < n ; i++) 
        cin >> a[i],  X^= a[i];

    if(n == 1) return 0;
    if(X == 0) return 1;

    int ans = 0;
    for(int i=0; i < n ; i++){
        if( (X ^ a[i] ) < a[i])
            ans++;
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