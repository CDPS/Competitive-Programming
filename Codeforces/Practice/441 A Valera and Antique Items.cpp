#include <bits/stdc++.h>

using namespace std;

int n, m, k, val;

void solve(){

    cin >> n >> k;

    vector<int> v;
    for(int i=1;i<=n;i++){
        cin >> m;
        while(m--){
            cin >> val;
            if(k > val)
                v.push_back(i);
        }
    }

    sort(v.begin(), v.begin());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v.size() << "\n";
    for(int i=0;i<v.size();i++)
        cout << v[i] << " \n"[i==v.size()-1];
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
