#include <bits/stdc++.h>

using namespace std;

int t, a, b;


void solve(){

    cin >> a >> b;

    vector<int> ans;
    for(int i=30;i>=0;i--){
        if( (b&(1<<i))!=0 ){
            if( (1<<i) > a ){
                cout << -1 << "\n";
                return;
            }
            if( (a&(1<<i))==0  )
                ans.push_back((1<<i));
        }else if( (a&(1<<i))!=0  ){
             ans.push_back((1<<i));
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " \n"[i==ans.size()-1];
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
         solve();
    return 0;
}


