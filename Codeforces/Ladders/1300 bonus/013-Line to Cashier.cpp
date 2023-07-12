#include <bits/stdc++.h>

using namespace std;

int oo = 10000000;
int a[100];

int main(){

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int res = oo;
    for(int i=0;i<n;i++){
        int acc = 0, k;
        for(int j=0;j<a[i];j++){
            cin >> k;
            acc += (k*5) + 15;
        }
        res = min(res,acc);
    }

    cout << res << "\n";
    return 0;
}
