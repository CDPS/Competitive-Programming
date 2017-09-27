#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double n,p;
    while(cin >> n >> p)
        cout << fixed << setprecision(0) << pow(p,1.0/n) << "\n";
    return 0;
}
