#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,x;
    cin >> n >> x;
    int res = (n>=x)? 1 : 0;
    for(int i=2 ;i<= min(n,x);i++){
        if(x%i==0 && (x/i) <=n )
            res++;
    }
    cout  << res << "\n";
    return 0;
}

