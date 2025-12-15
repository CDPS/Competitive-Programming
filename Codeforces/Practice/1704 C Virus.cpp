#include <bits/stdc++.h>

using namespace std;

int n, m, t;

int a[100000], r[100000];

int solve(){

   cin >> n >> m;

   for(int i=0;i<m;i++) cin >> a[i];
   sort(a, a + m);

    for(int i=1;i<m;i++)
        r[i-1] = a[i]-a[i-1] - 1;
    r[m-1] = a[0] + (n-a[m-1]) - 1;
    sort(r, r + m);

    int days = 0, acc = 0;
    for(int i=m-1; i>=0; i--)
        if(r[i] > days*2 )
           acc += max (1 , r[i] - days*2 - 1), days+=2;

    return n-acc;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

