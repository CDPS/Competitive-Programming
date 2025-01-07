#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n,m,k,x;
    cin >> t;

    while(t--){
        cin >> n >> m >> k;

        int acc = 0;
        for(int i=1;i<=n;i++) acc+=i;

        vector<int> v;
        for(int i=0;i<m;i++)
            cin >> x, v.push_back(acc-x);

        int acc2= 0;
        for(int i=0;i<k;i++)
            cin >> x, acc2+=x;

        for(int i=0;i<m;i++){
            if(k == n)  cout << 1;
            if(k <=n-2) cout <<0;
            if(k== n-1 && v[i] == acc2) cout << 1;
            if(k== n-1 && v[i] != acc2) cout << 0;
        }
        cout << "\n";
    }
    return 0;
}
