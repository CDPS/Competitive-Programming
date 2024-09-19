#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,k;
    cin >> t;
    while(t--){

        cin >> n >> k; k++;
        int h = (1<<n);
        int l = 0;
        int ans = 0;
        bool flag = false;

        while(n--){
            h/=2;
            int m = l + h;
            if(k > m ){
                if(!flag) ans+=(1<< n);
                l = m;
                flag=true;
            }else{
                if(flag) ans+=(1<< n);
                flag = false;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
