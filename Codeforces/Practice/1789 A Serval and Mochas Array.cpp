#include<bits/stdc++.h>

using namespace std;

int t, n;
int a[100];

bool solve(){

   for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(__gcd(a[i],a[j]) <=2 )
                return true;
    return false;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--){

        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a, a + n);

        cout << (solve()? "YES" : "NO" ) << "\n";
    }
    return 0;
}
