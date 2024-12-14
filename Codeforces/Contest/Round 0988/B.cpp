#include <bits/stdc++.h>

using namespace std;

int a[200000];
map<int, int> mp;

void solve(int n){
    int x = n-2;
    for(int i=0;i<n;i++){
        if( x%a[i] == 0 ){
            if(x/a[i] == a[i] && mp[a[i]]>1){
                cout << x/a[i] << " " << curr << "\n";
                return;
            }
            if(x/a[i] != a[i] && mp[x/a[i]] > 0){
                cout << x/a[i] << " " << a[i] << "\n";
                return;
            }
        }
    }
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t, n,x;
    cin >> t;

    while(t--){

        cin >> n;
        mp.clear();
        for(int i=0;i<n;i++)
            cin >> a[i], mp[a[i]]++ ;

        solve(n);
    }
    return 0;
}
