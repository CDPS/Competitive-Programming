#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int factors[6] = {1,2,3,4,6,12};

void solve(){

    cin >> s;

    vector<pair<int, int> > ans;
    for(int i=0;i < 6;i++){
        for(int j=0; j< 12/ factors[i]; j++){
            bool all_x = true;
            for(int k=j; k< 12; k+= 12/ factors[i])
                all_x &= s[k]=='X';
            if(all_x){
                ans.push_back({ factors[i], 12/ factors[i] });
                break;
            }
        }
    }

    cout << ans.size();
    for(int i=0;i<ans.size();i++)
        cout << " " << ans[i].first << "x" << ans[i].second;
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
