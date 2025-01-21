#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,a,b;
    cin >> t;

    while(t--){

        cin >> n >> a >> b;

        int dist = abs(a-b)-1;

        cout << (dist!=0 && dist%2  ? "YES" : "NO")  << "\n";
    }
    return 0;
}
