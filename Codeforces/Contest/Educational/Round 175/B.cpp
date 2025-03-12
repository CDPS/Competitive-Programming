#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t;
    ll n,x,k; string s;
    cin >> t;
    while(t--){

        cin >> n >> x >> k >> s;

        map<char,int> mp = { {'L', -1}, {'R', 1} };
        ll acc = 0;
        for(int i=0;i<n;i++){
            x += mp[s[i]];
            if(x == 0){ acc = i+1; break;}
        }

        k-= acc;
        ll ans = (x>0);
        if(x==0){
            acc = 0;
            for(int i=0;i<min(n, k);i++){
                x += mp[s[i]];
                if(x == 0){ acc = i+1; break; }
            }

            ans += (acc != 0? k/acc : 0);
        }

        cout << ans << "\n";
    }

    return 0;
}
