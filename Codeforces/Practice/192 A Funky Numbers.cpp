#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll n;

bool solve(){

    cin >> n;


    vector<ll> a;

    ll curr = 0, i = 1;
    while( curr <= n ){
        curr = (i*(i+1))/2ll;c
        a.push_back(curr);
        i++;
    }

    for(int i=0;i<a.size();i++)
        for(int j=i;j<a.size();j++)
            if(a[j] + a[i] == n)
                return true;
    return false;
}

int main(){


    cin.sync_with_stdio(false);
    cin.tie(NULL);

    t = 1;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";
}
