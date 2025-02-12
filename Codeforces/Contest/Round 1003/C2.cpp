#include <bits/stdc++.h>

using namespace std;

int a[200000], b[200001];
int t, n, m , x;

bool solve(){
    for(int i=1;i<=n;i++)
        if(a[i] < a[i-1]) return false;
    return true;
}

int upperBound(int x){
    int l=0, h = m-1,mid;
    while(l< h){
        mid = l + ( (h-l)/2 );
        if( b[mid] >= x)
             h = mid;
        else l = mid +1;
    }
    return b[l];
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--){
        cin >> n >> m;

        for(int i=0;i<n;i++) cin >> a[i+1];
        for(int i=0;i<m;i++) cin >> b[i];
        sort(b, b + m);
        a[0] = -2e9;

        for(int i=1;i<=n;i++){
            x = upperBound(a[i] + a[i-1]);
            if( min ( a[i], x-a[i]) >= a[i-1])
                a[i] = min ( a[i], x-a[i]);
            else
                a[i] = max (a[i], x-a[i]);
        }

        cout << (solve()? "YES" : "NO") << "\n";
    }
    return 0;
}
