#include <bits/stdc++.h>

using namespace std;

int t = 1, n;

int a[200001];
int b[200001];

bool solve(){

    cin >> n;
    for(int i=1; i<=n;i++)
        cin >> a[i], b[i] = a[i];

    sort(b , b + n + 1);

    for(int i=1;i<=n;i+=2){
        set<int> st;
        for(int j=i; j<=n; j*=2)
            st.insert(a[j]);
        for(int j=i; j<=n; j*=2)
            if(!st.count(b[j]))
                return false;
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
