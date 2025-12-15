#include <bits/stdc++.h>

using namespace std;

int t, n, m, d, x;
int pos[100001];
int   a[100001];

int solve(){

    cin >> n >> m >> d;
    for(int i=0; i <n; i++)
        cin >> x, pos[x] = i;
    for(int i=0;i<m; i++ )
        cin >> a[i];

    int ans = 1e9;
    for(int i = 1;i<m;i++){
        if(pos[ a[i-1] ] > pos[a[i]] )
            return 0;
        if( pos[a[i]] - pos[ a[i-1] ] >  d  )
            return 0;

        int dist = pos[a[i]] - pos[ a[i-1] ];
        ans = min( ans,  min( dist , d+1>= n? (int)1e9 : d + 1 - dist ) );
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
       cout <<  solve() << "\n";
    return 0;
}
