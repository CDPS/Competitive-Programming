#include <bits/stdc++.h>

using namespace std;

bool is_increasing(vector<int> & a){
    for(int i= 1; i < a.size(); i++)
        if(a[i] < a[i-1])
            return false;
    return true;
}

vector<int> factorize(int x) {

    if(x == 1) return {1};

    vector<int> factors;
    for (int i = 2; i * i <= x; i++)
        while (x % i == 0)
            factors.push_back(i), x /= i;

    if (x > 1)
        factors.push_back(x);

    reverse(factors.begin(), factors.end());

    return factors;
}

int t, n, x;

bool solve(){

    cin >> n;

    vector<int> a(n);
    for(int i=0; i < n; i++) cin >> a[i];

    if(is_increasing(a))return true;

    vector<int> v;
    for(int i=0; i < n; i++){
        auto f = factorize(a[i]);
        v.insert(v.end(), f.begin(), f.end());
    }

    return is_increasing(v);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "Bob" : "Alice" ) << "\n";

    return 0;
}
