#include <bits/stdc++.h>

using namespace std;

int n, k, x;

int solve(){

    cin >> n >> k;

    vector<int> freq(n + 1, 0);
    for(int i=0; i < n ; i++)
        cin >> x, freq[x]++;

    vector<int> pfx(n + 1, 0);
    for(int i=1; i<=n; i++)
        pfx[i] = freq[i] + pfx[i-1];

    int ans = 1;
    for(int g = n; g>= 1; g--){

        int top = min(n, (4*g) -1 );
        int saved = 0;
        if( 3*g<= top )  saved+= freq[3*g];
        if( 2*g<= top )  saved+= freq[2*g];
        if(   g<= top )  saved+= freq[g];

        if(pfx[top] - saved <= k){
            ans = g;
            break;
        }
    }

    return ans;
}

int t;
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
