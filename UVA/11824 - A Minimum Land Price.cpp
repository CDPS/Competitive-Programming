#include <bits/stdc++.h>

using namespace std;

typedef long ll;

int maxi = 5000000;

int main(){

    int t;
    cin >> t;

    while(t--){

        ll x;
        vector<ll> a;

        while(true){
            cin >> x;
            if(!x) break;
            a.push_back(x);
        }
        sort(a.begin(), a.end(), greater<int>());

        int p = 1;
        ll ans = 0;
        for(int i=0;i<a.size() && ans < maxi;i++)
            ans+= 2 * pow(a[i],p++);

        if(ans > maxi)
            cout << "Too expensive" << "\n";
        else
            cout << ans << "\n";
    }
    return 0;
}
