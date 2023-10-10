#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

pair<int, int > a[100000];

int main(){

    int n,d,x,y;

    cin >> n >> d;

    for(int i;i<n;i++){
        cin >> x >> y;
        a[i] = make_pair(x,y);
    }

    sort(a, a+ n);

    int j=0;
    long long ans = -1 ;
    long long acc = 0;

    for(int i=0;i<n;i++){
        while( j < n && a[j].f - a[i].f < d )
            acc += a[j++].s;
        ans = max(ans, acc);
        acc-= a[i].s;
    }
    cout << ans << "\n";
    return 0;
}
