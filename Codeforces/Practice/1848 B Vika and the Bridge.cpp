#include <bits/stdc++.h>

using namespace std;

int n, k, x;

int last[200001];

int solve(){

    cin >> n >> k;

    vector<int> last(k+1, -1);
    vector<pair<int,int>> v(k+1);

    for(int i=0;i<n;i++){
        cin >> x;
        int curr = (last[x]==-1)? i : (i-last[x])-1;
        if(curr >  v[x].first )
            v[x].second = v[x].first, v[x].first = curr;
        else
            v[x].second = max(v[x].second, curr);
        last[x] = i;
    }

    for(int i=1;i<=k;i++){
        int curr = (n-1)-last[i];
        if(curr >  v[i].first )
            v[i].second = v[i].first, v[i].first = curr;
        else
            v[i].second = max(v[i].second, curr);
    }

    int ans = 1e9;
    for(int i=1;i<=k;i++)
       ans= min(ans, max(v[i].first/2 ,  v[i].second ));

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
       cout << solve() << "\n";

    return 0;
}

