#include <bits/stdc++.h>

using namespace std;

int t, n;
string a, b;

bool solve(){

    int o = 0, e = 0;
    for(int i=0;i<n;i++){
        if(i%2==1 && b[i] == '0') o++;
        if(i%2==0 && a[i] == '1') e++;
    }
    if(e > o) return false;

    o = e = 0;
    for(int i=0;i<n;i++){
        if(i%2==1 && a[i] == '1') o++;
        if(i%2==0 && b[i] == '0') e++;
    }

    return o <= e;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--){

        cin >> n >> a >> b;

        cout << (solve()? "YES" : "NO" ) << "\n";
    }
    return 0;
}
