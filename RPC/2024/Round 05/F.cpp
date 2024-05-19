#include <bits/stdc++.h>

using namespace std;

int dist[21][21];
int memo[21][1<<21];

vector<int> a;
unordered_set<int> st;

int dp(int i, int mask){
    if (mask == ((1 << i) | 3)) return 0;
    if (memo[i][mask] != 0) return memo[i][mask];

    int res = 0;
    for (int j = 1; j <= a.size(); j++)
        if ((mask & (1 << j)) && j != i && j != 1)
            res = max(res, dp(j, mask & (~(1 << i))) + dist[j][i]);
    return memo[i][mask] = res;
}

int main(){

    int n,x;
    cin >> n;

    int ans = 0;

    for(int i=0;i<n;i++){
        cin >> x;
        if(!st.count(x))
            a.push_back(x), st.insert(x);
        else ans += x;
    }

    sort(a.begin(), a.end());

    for(int i=0; i< a.size();i++)
        for(int j=i+1;j<a.size();j++)
            dist[i+1][j+1] = dist[j+1][i+1] = __gcd(a[i],a[j]);

    int ans2 = 0;
    for (int i = 1; i <= a.size(); i++)
        ans2 = max(ans2, dp(i, (1 << (a.size() + 1)) - 1) + dist[i][1]);

    cout << ans + ans2  << "\n";
    return 0;
}
