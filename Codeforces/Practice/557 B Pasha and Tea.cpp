#include <bits/stdc++.h>

using namespace std;

int t = 1, n, w;
int a[200000];

double solve(){

    cin >> n >> w;

    for(int i = 0; i < 2*n; i++) cin >> a[i];

    sort(a, a + 2 * n);

    double mini = min( double(a[0] ), double(a[n])/2.0);

    return  min( double(w), 3.0 * n * mini);
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios_base::fixed);
    cout.precision(9);

    while(t--)
        cout << solve() << "\n";

    return 0;
}


