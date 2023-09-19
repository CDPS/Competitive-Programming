#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m,k,a1,ak;

    cin >> n;
    while(n--){
        cin >> m >> k >> a1 >> ak;

        int rqk = min(m/k, ak);
        m-= rqk * m;

        int res = 0;
        if(a1==0){
            res = m/k;
        }else{
            res = solve(m,k,a1);
        }

        m-= res *k;
        if(m > 0){
            if(a1 < m){
                m-=a1;
                res += m;
            }
        }
        cout << res << "\n";
    }

    return 0;
}
