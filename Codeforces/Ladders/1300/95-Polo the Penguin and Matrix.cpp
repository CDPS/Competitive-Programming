#include <bits/stdc++.h>

using namespace std;

int a[10000];
int n, m,d;

int main(){

    cin >> n >> m >> d;
    cin >> a[0];

    int limit = n*m;
    int mod = a[0]%d;
    bool ans = true;

    for(int i=1;i<limit;i++){
        cin >> a[i];
        ans&= (a[i]%d == mod);
    }

    if(ans){
        sort(a, a + (n*m));
        int mid = a[ (limit)/2 ];
        int res = 0;
        for(int i = 0; i<limit;i++){
            res+= abs( a[i]-mid) /d ;
        }
        cout << res << "\n";
    }
    else{
        cout << "-1" << "\n";
    }
    return 0;
}
