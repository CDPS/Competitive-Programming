#include <bits/stdc++.h>

using namespace std;

int t, n;
void solve(){

    cin >> n;

    if(n == 2){
        cout << "2 1 1 2 1 2 2 1" << "\n";
        return;
    }

    vector<int> ans;

    if(n %2 )
        ans.push_back(n);
    for(int i=1; i<=n; i++)
        ans.push_back(i);

    
    for(int i=1; i<=n; i+=2){
        ans.push_back(i);
        ans.push_back(i);
        ans.push_back(i+1);
        ans.push_back(i);
        ans.push_back(i+1);
        ans.push_back(i+1);
    }

    if(n %2 )
        ans.push_back(n), ans.push_back(n);

    for(int i=0; i < 4*n; i++)
        cout << ans[i] << " \n"[i==(4*n) -1];
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        solve();
    return 0;
}