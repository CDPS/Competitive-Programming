#include <bits/stdc++.h>

using namespace std;

int t = 1, n, k;

int C[35][35];
void precalc(){
    for (int i = 0; i < 35; i++)
        C[i][0] = 1;
    for (int i = 0; i < 35; i++)
        for (int j = 1; j <= i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
}

int solve(){

    cin >> n >> k;

    int l = 0;
    for(int i=31;i>=0;i--)
        if( (n&(1<<i)) !=0 ){
            l = i;
            break;
        }

    int acc = (l + 1 <= k);
    for(int i=1; i<= min(l, k ); i++){
        int free = i -1;
        int maxi = k - i;
        for(int j=0;j<= min(free, maxi); j++)
            acc += C[free][j];
    }

    return n - acc;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    precalc();

    cin >> t;
    while(t--)
        cout << solve() << "\n" ;

    return 0;
}

