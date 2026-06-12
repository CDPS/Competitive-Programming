#include <bits/stdc++.h>

using namespace std;

double const pi = acos(-1.0);

int t = 1, n;
int a[100];

double solve(){

    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];

    sort(a, a+n, greater<int>());

    int sum = 0;
    for(int i=0;i<n;i++)
        sum = (i%2==0)? sum + (a[i]*a[i]) : sum - (a[i]*a[i]);

    return pi*sum;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios_base::fixed);
    cout.precision(10);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
