
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, t;
ll a[200000];

int solve(){

    cin >> n;

    ll sum = 0;
    for(int i =0;i<n;i++)
        cin >> a[i], sum+=a[i];

    ll curr = 0;
    for(int i=0;i<n;i++){
        if( (curr + a[i])*2 >= sum )
            return i + 1;
        curr+=a[i];
    }

    return n;
}


int main(){

     cin.sync_with_stdio(false); cin.tie(NULL);


     cout << solve() << "\n";
}
