#include <bits/stdc++.h>

using namespace std;

int t, n, m;
int a[200000];

bool solve(){

    cin >> n >> m;

    for(int i= 0 ; i < n ; i++)
        cin >> a[i];

    for(int i= 1, curr = 1; i < n ; i++){
        if(a[i] == a[i-1] ){
            curr++;
            if(curr >= m)
                return false;
        }else{
            curr = 1;
        }
    }

    return true;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO" ) << "\n";

    return 0;
}
