#include <bits/stdc++.h>

using namespace std;

int a[1000];
int main(){

    int n, k, l, r, sall, sk;

    cin >> n >> k >> l >> r >> sall >> sk;
    sall-=sk;


    int m = sk / k;
    int mod = sk %k;
    for(int i=0;i< k;i++){
        a[i] = m ;
        if(mod > 0){
            a[i]++;
            mod--;
        }
    }

    if(k<n){
        m = sall / (n-k);
        mod = sall%(n-k);
        for(int i=k;i< n;i++){
            a[i] = m;
            if(mod > 0){
                a[i]++;
                mod--;
            }
        }
    }

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
