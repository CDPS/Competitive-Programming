#include <bits/stdc++.h>

using namespace std;

int main(){

    int t,n,m;
    string a, b;

    cin >> t;

    while(t--){

        cin >> n >> m >> a >> b;

        int red = 0, blue = 0;
        for(int i=0;i<n;i++)
            if(a[i]=='B') blue++;
            else red ++;

        for(int i=0;i<m;i++)
            if(b[i]=='B') blue++;
            else red ++;

        cout << ( red == blue-1 || blue == red-1? "YES" : "NO" ) << "\n";
    }
    return 0;
}
