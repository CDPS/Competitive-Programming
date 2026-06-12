#include <bits/stdc++.h>

using namespace std;

const int MAXI = 1e6;

int t = 1, n, x;

int solve(){

    cin >> n;

    vector<bool> a(MAXI  + 1);
    for(int i=0; i < n; i++)
        cin >> x, a[x] = true;

    int ans = 0;
    for(int i=1;i<=MAXI; i++){

        int curr = 0;
        for(int j=curr; j<=MAXI; j+= i)
            if(a[j])
                curr = __gcd(curr, j);

        if(curr == i && !a[i])
            ans++;
    }

    return ans;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}

