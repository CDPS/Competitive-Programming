#include <bits/stdc++.h>

using namespace std;

int t, n, x;
int    a[200001];
int idxs[200001];

bool solve(){

    cin >> n;

    for(int i=0;i<n;i++)
        cin >> x, idxs[x] = i;

    for(int i=0;i<n;i++) cin >> a[i];

    int last =  -1;
    for(int i=0;i<n;i++){

        int l = i,  r = i;
        while(a[r] == a[l]) r++;
        r--;

        if( last > idxs[a[l]])
            return false;

        last = idxs[a[l]];
        i = r;
    }

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
