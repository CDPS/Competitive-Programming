#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t = 1, n, m;

ll a[200000][26];
ll total_m[26];
ll total_p[26];

string s;

bool check(int x){

    for(int i = 0; i < 26; i++)
        if(total_m[i]< a[x][i])
            return false;
    return true;
}

void solve(){

    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        cin >> s;
        for(int j =0; j < s.size(); j++)
            a[i][s[j]-'A']++, total_m[s[j]-'A']+=m, total_p[s[j]-'A']++;
    }

    vector<ll> ans;
    for(int i=0; i < n; i++){

        for(int j=0; j < 26; j++)
            total_m[j] -= a[i][j]*m, total_p[j]-= a[i][j];

        if(!check(i)){
            ans.push_back(-1);
        }else{

            for(int j = 0; j < 26; j++)
                total_m[j]-= a[i][j];

            ll curr = 1e18;
            for(int j = 0; j < 26; j++)
                if(total_p[j] > 0)
                    curr = min(curr, total_m[j]/total_p[j]);

            ans.push_back(curr);

            for(int j = 0; j < 26; j++)
                total_m[j]+= a[i][j];
        }

        for(int j=0; j < 26; j++)
            total_m[j] += a[i][j]*m, total_p[j]+= a[i][j];
    }

    for(int i=0; i < n; i++)
        cout << ans[i] << " \n"[i==n-1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
