#include <bits/stdc++.h>

using namespace std;

int t = 1;

string a, b;

int solve(){

    cin >> a >> b;

    if(b.size() > a.size())
        return 0;

    int n = a.size();
    int m = b.size();

    int ans = 0;
    for(int i=0;i<=n-m;i++){
        bool check = true;
        for(int j = 0; j<m;j++)
            check &= (a[i+j] == b[j]);

        if(check)
            ans++, i+=m-1;
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
