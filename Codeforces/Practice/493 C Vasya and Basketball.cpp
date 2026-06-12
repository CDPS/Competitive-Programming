#include <bits/stdc++.h>

using namespace std;

int t = 1, n, m;

int a[200000];
int b[200000];
int c[400000];

void solve(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i], c[i] = a[i];

    cin >> m;
    for(int i=0;i<m;i++) cin >> b[i], c[i+n] = b[i];

    sort(a, a + n);
    sort(b, b + m);

    int max_diff = (n*3) - (m*3), max_score_a = n*3, max_score_b = m*3;
    for(int i=0;i<n+m;i++){

        int k = upper_bound(a, a+n, c[i] ) - a;
        int j = upper_bound(b, b+m, c[i] ) - b;

        int score_a = ((k)*2) + ((n-k)*3);
        int score_b = (j*2) + ((m-j)*3);

        if( score_a - score_b > max_diff || (score_a - score_b == max_diff && score_a > max_score_a ) ){
            max_diff = score_a - score_b;
            max_score_a = score_a;
            max_score_b = score_b;
        }
    }

    cout << max_score_a << ":" << max_score_b << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
