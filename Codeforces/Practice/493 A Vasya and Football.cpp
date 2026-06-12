#include <bits/stdc++.h>

using namespace std;

int t = 1, n;

int g[2][100];

string ss[2];
int minute, player;
char team, card;

void solve(){

    cin >> ss[0] >> ss[1] >> n;

    vector<pair<int,int>> ans(100, {-1, -1});
    while(n--){
        cin >> minute >> team >> player >> card;
        int h_team   = team == 'a';
        int h_card = card =='y'? 1 : 2;
        g[h_team][player] += h_card ;

        if( g[h_team][player] >= 2 )
            ans[minute] = {player, h_team};
    }

    set<pair<int, int> > st;
    for(int i=0;i<100;i++)
        if(ans[i].first != -1 && ans[i].second != -1 && !st.count({ans[i].first, ans[i].second}))
             cout << ss[ ans[i].second] << " " << ans[i].first << " " << i << "\n", st.insert({ans[i].first, ans[i].second});
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}

