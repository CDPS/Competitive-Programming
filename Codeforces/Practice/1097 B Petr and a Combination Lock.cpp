#include <bits/stdc++.h>

using namespace std;

int a[16];
int n;
int M = 360;

int add(int a, int b) {
    a += b;
    if (a >= M) a -= M;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) a += M;
    return a;
}

bool solve(int idx, int acc){
    if(idx == n )return acc == 0;
    return solve( idx + 1, add(acc, a[idx])) || solve( idx + 1, sub(acc, a[idx]));
}

int main(){

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    cout << (solve(0, 0)? "YES": "NO") << "\n";
    return 0;
}
