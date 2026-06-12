#include <bits/stdc++.h>

using namespace std;

int t =1;

int n, m, d;
int a[100];

int solve(){

    cin >> n  >> d;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cin >> m;

    sort(a, a + n);

    int sum = 0;
    for(int i=0; i < min(n, m); i++)
        sum+=a[i];

    return sum - ((m>n)? (m-n)*d : 0);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << solve() << "\n";

    return 0;
}
