#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, x;

int solve(){

    cin >> n;

    vector<int> a( 2*n + 2, 0);
    for(int i=0;i< 2*n; i++)
        cin >> x, a[x]++;

    int odds = 0, even_odd = 0, even = 0;
    for(int i=1;i <= 2*n; i++){
        if(a[i] == 0) continue;
        if(a[i] %2 ) odds++;
        if( a[i]%2  == 0 ){
            if(( a[i]/2)%2 )even_odd ++;
            else  even++;
        }
    }

    int ans = odds + even_odd * 2 + even * 2;

    if( odds ==0  && even%2 )
        ans -= 2;

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}



