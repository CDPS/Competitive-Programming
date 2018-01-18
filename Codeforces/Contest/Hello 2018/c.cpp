#include <bits/stdc++.h>

using namespace std;

long long cost[32];
long long    a[32];
long long oo = 1000000000000000000;
int n,L;

int main(){

    for(int i=0;i<32;i++) cost[i] = oo;

    cin >> n >> L;

    for(int i=0;i<n;i++) cin >> a[i] , cost[i]=a[i];

    for(long long i=1;i<n;i++)
        for(long long j=i-1,factor=2;j>=0;j--,factor*=2)
            cost[i] = min(cost[i], factor*a[j]);

    for(int i=n;i <32;i++) cost[i] = cost[i-1]*2;

    long long ans = oo, part= 0;

    for(int i=31;i>=0;i--){
        if( ( L & (1<<i) ) != 0 ) part = part + cost[i];
        else ans = min( ans, part + cost[i]);
    }

    ans = min(ans , part);
    cout << ans << "\n";
    return 0;
}
