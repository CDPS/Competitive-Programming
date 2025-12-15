#include <bits/stdc++.h>

using namespace std;

int t;
string sa, sb;

void solve(){

    cin >> sa >> sb;

    vector<int> a(27,0), b(27, 0);
    for(int i=0;i <sa.size();i++)
        a[ sa[i]-'a']++;
    for(int i=0;i <sb.size();i++)
        b[ sb[i]-'a']++;

    for(int i= 0; i <27; i++){
        if(a[i] > b[i]){
            cout << "Impossible" << "\n";
            return;
        }
    }

    for(int i=0; i< sa.size();i++){
        int curr = sa[i]-'a';
        for(int j= 0; j<curr;j++){
            while(b[j]-a[j] > 0){
                cout << char(j + 'a');
                b[j]--;
            }
        }
        cout << sa[i];
        a[curr]--;
        b[curr]--;
    }

    for(int j= 0; j<27;j++){
        while(b[j] > 0){
            cout << char(j + 'a');
            b[j]--;
        }
    }
    cout << "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        solve();

    return 0;
}
