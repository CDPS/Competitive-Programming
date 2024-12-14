#include <bits/stdc++.h>

using namespace std;

int a[100000];
int t,n,k;

int solve(){
    int res = 10000;
    for(int i=0;i<n;i++){
        for(int j=0;j<=5;j++){
            if( (a[i] + j ) % k ==0){
                res = min( res, j);
            }
        }
    }
    return res;
}

int main(){

    cin >> t;
    while(t--){

        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> a[i];

        int res = 10000;
        if(k ==4){
            int even = 0;
            for(int i=0;i<n;i++){
                if(a[i]%2==0)
                    even++;
            }
            res = max(0, 2-even);
        }
        res = min(res, solve());
        cout << res << "\n";
    }
    return 0;
}
