#include <bits/stdc++.h>

using namespace std;

int main(){

    int l, p, q;

    cin >> l;
    cin >> p;
    cin >> q;

    double x = (double)l/(double)(p+q);

    cout << (double)p * x << "\n";

    return 0;
}
