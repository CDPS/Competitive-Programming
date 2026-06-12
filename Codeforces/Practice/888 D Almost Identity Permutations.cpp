#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n, k;

int ways[5] = {1 , 0, 1, 2 , 9};

ll nCk[1001][5];

void precalc(){
    for (int i = 0; i <= 1000; i++)
        nCk[i][0] = 1;
    for (int i = 1; i <=1000; i++)
        for (int j = 1;j <= min(i, 4); j++)
            nCk[i][j] = nCk[i - 1][j - 1] + nCk[i - 1][j];
}

ll solve(){

    cin >> n >> k;

    ll ans  = 0;
    for(int i=0; i <=k ; i++)
        ans+= ways[i]* nCk[n][i];

    return ans;
}

int main(){

    precalc();

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
