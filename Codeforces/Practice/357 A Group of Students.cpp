#include <bits/stdc++.h>

using namespace std;

int t = 1, n, x, y;
int a[100];

int solve(){

    cin >> n;

    int sum = 0;
    for(int i=0; i<n; i++)
        cin >> a[i], sum+= a[i];
    cin >> x >> y;

    for(int i=0, curr = 0;i < n;i++ ){
        curr += a[i];
        if(curr >= x && curr <=y && sum-curr >=x && sum-curr <= y )
            return i+ 2;
    }

    return 0;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
