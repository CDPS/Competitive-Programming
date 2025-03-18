#include <bits/stdc++.h>

using namespace std;

int getMin(int x, int n, int m) {
    while (x > 1 && (n > 0 || m > 0)) {
        if (m > 0) {
            x = (x + 1) / 2;
            m--;
        } else {
            x /= 2;
            n--;
        }
    }
    if(x==1 && n > 0) x/=2;
    return x;
}

int getMax(int x, int n, int m) {
    while (x > 1 && (n > 0 || m > 0)) {
        if (n > 0) {
            x /= 2;
            n--;
        } else {
            x = (x + 1) / 2;
            m--;
        }
    }
    if(x==1 && n > 0) x/=2;
    return x;
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, m, x;
    cin >> t;

    while(t--){

        cin >> x >> n >> m;
        cout << getMin(x,n,m) << " " << getMax(x,n,m) << "\n";
    }
    return 0;
}
