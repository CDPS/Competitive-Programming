#include <bits/stdc++.h>

using namespace std;

int t = 1;

int n;
string a[300];

int solve(){

    cin >> n;

    set<char> st;
    for(int i=0;i<n;i++){
        cin >> a[i];
        for(int j=0;j<n;j++)
            st.insert(a[i][j]);
    }

    if(st.size() != 2) return false;

    for(int i=0;i<n;i++)
        if( a[i][i] != a[0][0] || a[i][n-1-i] != a[0][0] )
            return false;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            if( j!=i && j!=n-1-i && a[i][j] == a[0][0] )
                return false;
    }
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}

