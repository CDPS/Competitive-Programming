#include <bits/stdc++.h>

using namespace std;

int t= 1, n, k;

void solve(){

    cin >> n >> k;

    vector<vector<char>> v(4, vector<char>(n, '.'));
    if (k % 2 == 0) {
        for(int i = 1; i <= k / 2; i++)
            v[1][i] = '#', v[2][i] = '#';
    } else {

        int mid = n / 2;
        v[1][mid] = '#';

        int curr = 1;
        for(int d = 1; d <= mid - 1 && curr < k; d++, curr+=2)
            v[1][mid - d] = v[1][mid + d] = '#';
        for(int d = 1; d <= mid - 1 && curr < k; d++, curr+=2)
            v[2][mid - d] = v[2][mid + d] = '#';
    }

    cout << "YES\n";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            cout << v[i][j];
        }
        cout << "\n";
    }
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        solve();

    return 0;
}
