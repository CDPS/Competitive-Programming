#include <bits/stdc++.h>

using namespace std;

int a[100];
int t,n,k;

void solve(){
    for(int i=0;i<n;i++){

        bool flag = false;
        for(int j=0;j<n;j++){
            if(i!=j)
                flag |= abs(a[j]-a[i])%k ==0;
        }

         if(!flag){
            cout << "YES" << "\n" << i+1 << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--){

        cin >> n >> k;

        for(int i=0;i<n;i++)
            cin >>a[i];

        solve();
    }
    return 0;
}
