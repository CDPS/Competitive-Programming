#include <bits/stdc++.h>

using namespace std;

int t = 1, n, k;
int a[1000];

void solve(){

    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> a[i];

    int best_idx = -1, best_curr = 1e9;
    for(int i=0; i < n; i++){

        if (a[i] - (i * k) <= 0) continue;

        int curr = 0;
        for(int j = i - 1; j >= 0; j--)
            curr+= (a[j] != a[i] - ((i - j) * k));
        for(int j = i + 1; j < n; j++)
            curr +=(a[j] != a[i] + ((j - i) * k));

        if(curr < best_curr)
            best_curr = curr, best_idx = i;
    }

    cout << best_curr << "\n";
    for(int j = best_idx-1; j>=0; j--){
        int curr = a[best_idx] - ((best_idx - j) * k);
        if(a[j] != curr)
            cout << ( a[j] > curr ? '-' : '+' ) << " "  << j + 1 << " " << abs(curr - a[j]) << "\n";
    }
    for(int j = best_idx+1; j < n; j++){
        int curr = a[best_idx] + ((j - best_idx) * k);
        if(a[j] != curr)
            cout << ( a[j] > curr ? '-' : '+' ) << " " << j + 1 << " " << abs(curr - a[j]) << "\n" ;
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
