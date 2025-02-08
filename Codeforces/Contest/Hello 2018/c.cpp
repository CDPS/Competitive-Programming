#include <bits/stdc++.h>

using namespace std;

long long cost[32];
long long oo = 2e18;
int n,L;

int main(){

    for(int i=0;i<32;i++) cost[i] = oo;

    cin >> n >> L;

    for(int i=0;i<n;i++) cin >> cost[i];

    for(int i=1;i<32;i++)
        cost[i]= min(cost[i], 2*cost[i-1]);

    long long ans = oo, part= 0;
    for(int i=31;i>=0;i--){
        if( ( L & (1<<i) ) != 0 ) part = part + cost[i];
        else ans = min( ans, part + cost[i]);
    }

    ans = min(ans , part);
    cout << ans << "\n";
    return 0;
}
