#include <bits/stdc++.h>

using namespace std;

int a[200];
int t, n;

bool check(int x, int y, int z){
    return x+y >z && y+z>x && x+z>y;
}

bool solve(){
    for(int i=0;i<n-1;i++)
        if(check(a[i],a[i+1], a[i]) && check(a[i],a[i+1], a[i+1]))
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

        cout << ( solve()? "YES": "NO" ) << "\n";
    }
    return 0;
}
