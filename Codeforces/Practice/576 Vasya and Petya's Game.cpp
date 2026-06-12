#include <bits/stdc++.h>

using namespace std;

int n, t = 1;

int f(int x){

    int ans = 0;
    for(int p=2; p*p <= x; p++){
        if(x%p==0){
            ans++;
            while(x%p==0)  x/=p;
        }
    }
    if(x != 1)
        ans++;
    return ans;
}

void solve(){

    cin >> n;

    vector<int> ans;
    for(int i=2;i <=n; i++){
        if(f(i)==1)
            ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for(int i=0;i < ans.size();i++)
        cout << ans[i] << " \n"[i==ans.size()-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
