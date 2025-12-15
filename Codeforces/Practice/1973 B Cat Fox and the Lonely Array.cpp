#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
const int LOGN = log2(MAXN) + 1;

int st[MAXN][LOGN];
int l[MAXN + 1];
int a[MAXN + 1];

int t, n;

void build_log(int n) {
    l[1] = 0;
    for (int i = 2; i <= n; i++)
        l[i] = l[i / 2] + 1;
}

void build() {
    build_log(n);
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
    for (int j = 1; j < LOGN; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = st[i][j - 1] | st[i + (1 << (j - 1))][j - 1];
}

int query(int L, int R) {
    int j = l[R - L + 1];
    return st[L][j] | st[R - (1 << j) + 1][j];
}

bool check(int k) {

    int target = 0;
    for (int i=0;i<k;i++) target|= a[i];

    for (int i = 1; i <= n - k; ++i)
        if (query(i, i + k - 1) != target)
            return false;

    return true;
}

int solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    build();

    int l = 1, h = n, m;
    while(l< h){
         m = l + ( (h-l)/2 );
        if(check(m))
             h = m;
        else l = m +1;
    }
    return l;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
