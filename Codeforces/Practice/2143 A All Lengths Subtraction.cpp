
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
int a[100];

bool solve(){

    cin >> n;

    int i = 0, j= 0;
    for(int k=0;k<n;k++){
        cin >> a[k];
        if(a[k] == n)
            i=k, j=k;
    }

    int current = n;
    while(current> 1){
        int nexti = max(0, i-1);
        int nextj = min(n, j+1);
        if(a[nexti] == current -1 )
            current--, i = nexti;
        else if(a[nextj] == current -1 )
            current--, j = nextj;
        else
            return false;
    }

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()?"YES" : "NO" ) << "\n";

    return 0;
}
