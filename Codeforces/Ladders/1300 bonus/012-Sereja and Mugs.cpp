#include <bits/stdc++.h>

using namespace std;

int a[100];
int n,s;

bool solve(){

    for(int i=0;i<n-1;i++){
        s-=a[i];
        if(s<0)
            return false;
    }
    return true;
}

int main(){

    cin >> n >> s;

    for(int i=0;i<n;i++)
       cin >> a[i];

    sort(a,a + n);

    cout << ( solve()? "YES" : "NO" ) << "\n";

    return 0;
}

