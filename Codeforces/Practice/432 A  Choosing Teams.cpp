#include <bits/stdc++.h>

using namespace std;

int n, k, x;

int solve(){

    cin >> n >> k;

    int acc = 0;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x <= 5-k)
            acc++;
    }

    return acc/3;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}

