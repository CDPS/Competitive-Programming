#include <bits/stdc++.h>

using namespace std;

int main(){
    int a1,a2,a3;
    cin >> a1 >> a2 >> a3;
    vector<int > v;
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);
    sort(v.begin(),v.end());

    a1 = v[0]; a2 = v[1]; a3 = v[2];
    int w1 = sqrt( (a1*a2)/a3 )*4;
    int w2 = sqrt( (a1*a3)/a2 )*4;
    int h1 = sqrt( (a2*a3)/a1 )*4;

    cout << w1 + w2 + h1 << "\n";

    return 0;
}
