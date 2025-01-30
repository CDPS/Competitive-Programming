#include <bits/stdc++.h>

using namespace std;

int n,k;
int a[100];

bool solve(){
    if(k== 1){
        for(int i=1;i<n;i++)
            if(a[i] < a[i-1])
                return false;
    }
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){

        cin >> n >> k;
        for(int i=0;i<n;i++) cin >> a[i];

        cout << ( solve()? "YES" : "NO" ) << "\n";
    }
    return 0;
}
