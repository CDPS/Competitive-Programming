#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll d[200000];
ll a[100000];

int t, n;

bool solve(){

    cin >> n;

    set<ll> st;
    for(int i=0;i<2*n;i++)
        cin >> d[i], st.insert(d[i]);

    if(st.size() != n) return false;

    sort(d , d + (2*n), greater<ll>());

    ll acc = 0;
    for(int i=0,j=0; i<2*n;i+=2, j++){

        if(d[i] != d[i+1] ) return false;

        a[j] = d[i] - 2*acc;

        if(a[j] <= 0 || a[j]%(2*(n-j)) !=0 ) return false;

        a[j]/= (2*(n-j)) ;

        acc+= a[j];
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

