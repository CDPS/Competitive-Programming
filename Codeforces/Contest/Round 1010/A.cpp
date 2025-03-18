#include <bits/stdc++.h>

using namespace std;

bool a[100][100];
bool r[100],c[100];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, m;
    cin >> t;

    while(t--){

        cin >> n >> m;

        memset(r, 0, sizeof r);
        memset(c, 0, sizeof c);

        string s;
        for(int i=0;i<n;i++){
            cin >> s;
            for(int j=0;j<m;j++)
                r[i]^= (s[j]-'0'), c[j]^= (s[j]-'0');
        }


        int rows = 0, cols =0;
        for(int i=0;i<n;i++) rows += r[i];
        for(int i=0;i<m;i++) cols += c[i];

        cout << max(rows, cols) << "\n";
    }
    return 0;
}
