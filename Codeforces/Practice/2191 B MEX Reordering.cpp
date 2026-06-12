#include <bits/stdc++.h>

using namespace std;

int t, n;
int a[100];

int f(int s, int e){
    int mex =0;
    for(int i=s;i<=e;i++)
        if(a[i] == mex)
            mex++;
    return mex;
}

bool solve(){

    cin >> n;
    for(int i=0;i<n; i++)
        cin >> a[i];

    sort(a, a + n);

    for(int i=0;i < n -1; i++)
        if(f(0, i ) == f(i+1, n-1))
            return false;

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << ( solve()? "YES" : "NO") << "\n";

    return 0;
}



