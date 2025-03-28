#include<bits/stdc++.h>

using namespace std;

int t, n, m;
string a;

bool check(int l, int r){
    for(int i=l;i<=r;i++)
        if(a[i] == a[n-1-i])
            return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);


    cin >> t;
    while(t--){

        cin >> n >> a;

        m = (n/2) -1;

        int l = 0, r = m;
        bool f = false;

        for(int i= 0;i<=m ;i++){
            if(a[i]!=a[n-1-i]){
                l = i, f= true;
                break;
            }
        }

        for(int i= m, j= n%2? (n/2)+1 : n/2 ; i>=0; i--, j++){
            if(a[i]!=a[j]){
                r = i,  f = true;
                break;
            }
        }

        cout << ( !f || check(l,r)? "YES" : "NO" ) << "\n";
    }
    return 0;
}
