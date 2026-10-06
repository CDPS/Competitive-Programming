#include <bits/stdc++.h>

using namespace std;

int t, n, c;

int a[100];
int b[100];

int solve(){

    cin >> n >> c;

    for(int i=0; i < n; i++) cin >> a[i];
    for(int i=0; i < n; i++) cin >> b[i];

    int ans1 = 0;
    for(int i=0 ; i < n ; i++){
        if(a[i] < b[i]){
            ans1 = 1e9;
            break;
        }
        ans1+= a[i] - b[i];
    }

    sort(a, a + n);
    sort(b, b + n);
    
    int ans2 = c;
    for(int i=0; i < n; i++){
        if(a[i] < b[i]){
            ans2 = 1e9;
            break;
        }
        ans2+= a[i] - b[i];
    }
    
    int ans = min(ans2, ans1);
    
    return ans == 1e9? -1 : ans;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
       cout << solve() << "\n";
    return 0;
}