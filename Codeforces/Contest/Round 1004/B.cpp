#include <bits/stdc++.h>

using namespace std;

int t,n,x;
int a[1002];

bool solve(){
    for(int i=1;i<=n;i++)
        if(a[i]!=0) return false;
    return a[n+1]%2 == 0 ;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<=n+1;i++) a[i] = 0;
        for(int i=0;i<n;i++) cin >> x, a[x]++;

        for(int i=1;i<=n;i++)
            if(a[i]>=2)
                a[i]-=2, a[i+1] += a[i], a[i] = 0;

        cout << ( solve()? "YES" : "NO"  ) << "\n";
    }
    return 0;
}
