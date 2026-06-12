#include <bits/stdc++.h>

using namespace std;


int t, n;
int a[200000];

int solve(){


    int mini = 1e9;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    sort(a, a+ n);

    return max(a[0],a[1] - a[0]);
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";
}
