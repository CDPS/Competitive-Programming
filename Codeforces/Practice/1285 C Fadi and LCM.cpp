#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

int main(){

    ll n;
    cin >> n;

    ll a = 0, b=0;
    for(ll i=1; i*i <=n;i++){
        if(n%i==0 && lcm(i, n/i) == n)
            a=i, b = n/i;
    }

    cout << a << " " << b << "\n";
    return 0;
}
