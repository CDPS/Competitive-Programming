#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll    p[100000];
ll    q[100000];
ll  ans[100000];
ll pow2[100000];

const ll mod = 998244353;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    pow2[0] = 1;
    for(int i = 1; i < 100000; i++)
        pow2[i] = (pow2[i-1] * 2LL) % mod;

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;
        for(int i=0;i<n;i++) cin >> p[i];
        for(int i=0;i<n;i++) cin >> q[i];

        int maxip = -1, maxiq = -1, ip, iq;
        for(int i=0;i<n;i++){

            if(p[i] > maxip)
                maxip = p[i], ip = i;

            if(q[i] > maxiq)
                maxiq = q[i], iq = i;

            int L, S;
            if (maxip > maxiq)
                L = maxip, S = q[i - ip];
            else if (maxiq > maxip)
                L = maxiq, S = p[i - iq];
            else
                L = maxip, S = max(q[i - ip], p[i - iq]);

            ans[i] = (pow2[L] + pow2[S] )%mod;
        }

        for(int i=0;i<n;i++)
            cout << ans[i] << " \n"[i==n-1];
    }
    return 0;
}
