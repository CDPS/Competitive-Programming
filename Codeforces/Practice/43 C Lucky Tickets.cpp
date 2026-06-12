#include <bits/stdc++.h>

using namespace std;

int t = 1, n, ai;
int a[3];

int f(int x){
    int sum = 0;
    while(x > 0)
        sum += x%10, x/=10;
    return sum%3;
}

int solve(){

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> ai, a[ f(ai)]++;

    return min(a[2],a[1]) + (a[0]/2);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
