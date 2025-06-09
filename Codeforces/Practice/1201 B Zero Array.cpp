#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int n, x, maxi = -1; ll sum = 0;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> x, sum += x, maxi = max(x, maxi);

    cout << ( sum%2 == 0 && maxi <= sum -maxi? "YES" : "NO" ) << "\n";

    return 0;
}

