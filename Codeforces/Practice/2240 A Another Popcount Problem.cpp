#include <bits/stdc++.h>

using namespace std;

int t, n , k;

int col(int x){
    int ans = 0;
    for(int i=0; i < 31; i++){
        for(int j=0; j < k ; j++){
            if(  (1<<i) > x  ) return ans;
            ans++;
            x-= (1<<i);
        }
    }
    return ans;
}

int row(int x){
    int ans = 0;
    for(int j=0; j < k ; j++){
        for(int i=0; i < 31; i++){
            if(  (1<<i) > x  ) return ans;
            ans++;
            x-= (1<<i);
        }
    }
    return ans;
}

int solve(){
    cin >> n >> k;
    if(k>=n) return n;
    return max(col(n), row(n));
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << solve() << "\n";
    return 0;
}