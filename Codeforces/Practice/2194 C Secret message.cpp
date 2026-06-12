#include <bits/stdc++.h>

using namespace std;

int t, n, k;
string s;

void solve(){

    cin >> n >> k;

    vector<int> masks(n, 0);
    for(int i=0;i<k;i++){
        cin >> s;
        for(int j=0;j<n;j++)
            masks[j] |= (1<<s[j]-'a');
    }

    vector<int> div;
    for(int i=1; i*i <= n;i++){
        if(n % i == 0){
            div.push_back(i);
            if(i != n/i)
                div.push_back(n/i);
        }
    }
    sort(div.begin(), div.end());

    for (int d : div) {

        string ans = "";
        bool check = 1;
        for(int i = 0; i < d; i++){

            int curr = (1 << 26) - 1;
            for(int j=i; j < n; j+= d)
                curr&=masks[j];

            if(curr == 0){
                check = false; break;
            }

            ans += ('a' + __builtin_ctz(curr));
        }

        if(check){

            for(int i=0; i< n/d;i++ )
                cout << ans;
            cout << "\n";
            return;
        }
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
