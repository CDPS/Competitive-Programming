#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double EP = 1e-7;

int n;
ll a[60000], b[60000];

bool f(double x){
    double l = LLONG_MIN, r = LLONG_MAX;
    for(int i=0;i<n;i++){
        l = max(l, a[i] - (b[i]*x) );
        r = min(r, a[i] + (b[i]*x) );
    }
    return l<=r;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios_base::fixed);
    cout.precision(12);

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    double l = 0, h = 2e18, m;
    while(h-l > EP){
        m = l + ( (h-l)/2 );
        if(f(m))
            h = m;
        else
            l = m;
    }

    cout << l << "\n";

    return 0;
}
