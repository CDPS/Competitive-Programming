#include <bits/stdc++.h>

using namespace std;

int main(){

    int c1, c2, c3;
    int m1, m2, m3;
    int n;
    cin >> c1 >> c2 >> c3;
    cin >> m1 >> m2 >> m3;
    cin >> n;

    int c = c1 + c2 + c3;
    int m = m1 + m2 + m3;

    int amountCoups  = (c%5==0)? c/5   : (c/5) + 1;
    int amountMedals = (m%10==0)? m/10 : (m/10) + 1;

    cout << ( (amountCoups+amountMedals <= n)? "YES" : "NO" ) << "\n";
    return 0;
}
