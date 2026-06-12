#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int LOG = 19;

int t, n;
int a[2][MAXN];

int st[MAXN][19];
int lg[MAXN];

void precompute_logs() {
    lg[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}

void build(const vector<int>& pfx, const vector<int>& sfx, int n) {

    for (int i = 1; i <=n; i++)
        st[i][0] = max(pfx[i], sfx[i]);

    for (int j = 1; j < LOG; j++)
        for (int i = 1; i + (1 << j) <= n + 1 ; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R) {
    int j = lg[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

ll solve(){

    cin >> n;

    for(int i= 1; i <=n; i++) cin >> a[0][i];
    for(int i= 1; i <=n; i++) cin >> a[1][i];

    vector<int> pfx(n + 2, -1);
    vector<int> min_l(2 *n + 1, n + 1);
    for(int i=1; i <=n; i++){
        pfx[i] = max(a[0][i], pfx[i-1]);
        min_l[ a[0][i] ] = min(i, min_l[a[0][i]]);
    }

    vector<int> sfx(n + 2, -1);
    vector<int> max_l(2 *n + 1, 0);
    for(int i=n; i >=1; i--){
        sfx[i] = max(a[1][i], sfx[i + 1]);
        max_l[ a[1][i] ] = max(i, max_l[a[1][i]]);
    }

    build(pfx, sfx, n);

    ll ans = 0;
    int min_j1 = n + 1, max_j2 = 0;
    for (int l = 1; l <= 2 * n; l++) {

        if (l > 1) {
            min_j1 = min(min_j1, min_l[l - 1]);
            max_j2 = max(max_j2, max_l[l - 1]);
        }

        int L_k = max_j2 + 1, R_k = min_j1 - 1;
        if (L_k <= R_k) {
            int min_r = query(L_k, R_k);
            if (min_r <= 2 * n)
                ans += (2 * n - min_r + 1);
        }
    }

    return ans ;
}

int main(){

    precompute_logs();

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
