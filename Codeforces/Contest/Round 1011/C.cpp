#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    long long x , y, k;

    cin >> t;

    while(t--){

        cin >> x >> y ;

        cout << (  x!=y ? ( (1ll<<50)-max(x,y) ) : -1 ) << "\n";
    }
    return 0;
}
