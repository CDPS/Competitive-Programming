#include <bits/stdc++.h>

using namespace std;

int t = 1;

string a, b, c;

vector<int> count_a(26, 0);
vector<int> count_b(26, 0);
vector<int> count_c(26, 0);

void solve(){

    cin >> a >> b >> c;
    for(int i=0; i < a.size(); i++)count_a[ a[i]-'a']++;
    for(int i=0; i < b.size(); i++)count_b[ b[i]-'a']++;
    for(int i=0; i < c.size(); i++)count_c[ c[i]-'a']++;

    int best_b = 0, best_c = 0;
    for(int i=0; i<= a.size(); i++){

        vector<int> curr = count_a;

        bool can = true;
        for(int j=0; j < 26 && can ; j++)
            can &= curr[j] >= count_b[j] * i, curr[j] -= count_b[j] * i;

        if(!can) break;

        int acc_c = 1e9;
        for(int j=0; j < 26; j++)
            if(count_c[j] != 0)
                acc_c = min(acc_c, curr[j]/count_c[j] );

        if( i + acc_c > best_b + best_c)
            best_b = i, best_c = acc_c;
    }

    for(int j=0; j < 26 ; j++)
        count_a[j] -= (best_b* count_b[j]) +  (best_c* count_c[j]);

    while(best_b--) cout << b;
    while(best_c--) cout << c;
    for(int j=0; j < 26 ; j++)
        while(count_a[j]--)
            cout << char(j + 'a');

    cout << "\n";
}


int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
