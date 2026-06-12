#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[21];

bool solve(){

    cin >> n;

    a[0] = 0;
    for(int i=1;i<=n;i++) cin >> a[i];

    int pow_2 = 4;
    for(int i= 3; i <=n;i++){
        if(i == pow_2) pow_2*=2;
        if(i == (pow_2/2) + 1) continue;
        if(a[i] < a[i-1]) return false;
    }

    return true;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
