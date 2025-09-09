#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, a, x, y;
    cin >>t;

    while(t--){

        cin >> a >> x >> y;
        if(x > y)
            swap(x, y);

        cout << (   a>=x && a<= y ? "NO" : "YES") << "\n";
    }
    return 0;
}
