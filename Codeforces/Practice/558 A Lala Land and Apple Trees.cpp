#include <bits/stdc++.h>

using namespace std;

int t = 1, n, xi, ai;

int process(vector< pair<int,int> > &a,vector< pair<int,int> > &b ){

    if(a.size() > b.size())
        swap(a, b);

    int ans = 0;
    for(int i=0;i<a.size();i++)
        ans+= a[i].second;
     for(int i=0;i<a.size()+ (a.size() != b.size());i++)
        ans+=b[i].second;
    return ans;
}

int solve(){

    cin >> n;

    vector< pair<int,int> > neg, pos;
    for(int i=0;i<n;i++){
        cin >> xi >> ai;
        if(xi < 0)
            neg.push_back({xi, ai});
        else
            pos.push_back({xi, ai});
    }

    sort(neg.begin(), neg.end(), greater<pair<int,int>>());
    sort(pos.begin(), pos.end());

    return process(neg, pos);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
