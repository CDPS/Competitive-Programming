#include <bits/stdc++.h>

using namespace std;

int a[200001][30];

int f(int l, int r){
    int ans  = 0;
    for(int j = 29; j>=0;j--)
        if( a[r][j] - a[l-1][j] == r-l+1 )
            ans+= (1<<j);
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x, q, k, l, h , m, qp;
    cin >> t;

    while(t--){

        cin >> n;

        for(int i=1;i<=n;i++){
            cin >> x;
            for(int j = 29; j>=0;j--)
                 a[i][j] = (x&(1<<j))!= 0,a[i][j]+= a[i-1][j];
        }

        cin >> q;
        while(q--){

            cin >> qp >> k ; l = qp; h = n;

            if(f(l,l) < k){
                cout << -1 << " \n"[q==0];
                continue;
            }

            while(h-l>1){
                m = l + ( (h-l)/2 );
                if(f(qp,m) >= k)
                    l = m;
                else
                    h = m - 1;
            }

            cout << ( (f(qp,h)>=k)? h : l )<< " \n"[q==0];
        }
    }
    return 0;
}
