#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;

void solve(){

    cin >> n >> k >> s;

    vector<vector<int>>     dp( n + 1, vector<int>(k, 1e9));
    vector<vector<int>> parent( n + 1, vector<int>(k, -1));

    for(int i=0;i<k;i++)
        dp[0][i] = s[0] != i + 'A';

    for(int i=1;i<n;i++)
        for(int j=0;j<k;j++)
            for(int l = 0; l < k; l++)
                if( l!=j && (j + 'A' !=  s[i]) + dp[i-1][l] < dp[i][j])
                    dp[i][j] = (j + 'A' !=  s[i]) + dp[i-1][l], parent[i][j] = l;

    int mini = 1e9, idx= 0;
    for(int i=0;i<k;i++)
        if(mini > dp[n-1][i] )
            mini = dp[n-1][i], idx = i;

    stack<char> st;
    for(int i=n-1;i>=0;i--)
        st.push( 'A' + idx ), idx = parent[i][idx];

    cout << mini << "\n";
    while(!st.empty())
        cout << st.top(), st.pop();
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
