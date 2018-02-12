#include <bits/stdc++.h>

using namespace std;

int main()
{

    int a,b,c;
    cin >> a >> b >> c;

    int r1 = a/3; a%=3;
    int r2 = b/3; b%=3;
    int r3 = c/3; c%=3;

    cout << r1 + r2 +r3 + ( (a+b+c)/3 ) << "\n";
    return 0;
}
