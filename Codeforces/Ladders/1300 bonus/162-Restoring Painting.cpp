#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,a,b,c,d;

    cin >> n >> a >> b >> c >> d;

    long long res = 0;
    for(int i=1;i<=n;i++){

        int fc = i + b  - c;
        int sc = i + a  - d;
        int tc = a + fc - d;

        if( fc >=1 && fc <=n &&
            sc >=1 && sc <=n &&
            tc >=1 && tc <=n )
                res++;
    }
    cout << res*n << "\n";
    return 0;
}
