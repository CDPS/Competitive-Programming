#include <bits/stdc++.h>

using namespace std;


int n, m;

string g[100];

int getV(int i, int j) {

    int l = i, r = i;

    while (l >= 0 && g[l][j] == '.')  l--;
    l++;

    while (r < n && g[r][j] == '.')  r++;
    r--;

    return (r - l + 1 < m)? 0 : max(0, min(r- m + 1,  i) - max(l, i - m + 1) + 1);
}

int getH(int i, int j) {

    int l = j, r = j;

    while (l >= 0 && g[i][l] == '.')  l--;
    l++;

    while (r < n && g[i][r] == '.')  r++;
    r--;

    return (r - l + 1 < m)? 0 : max(0, min(r- m + 1,  j) - max(l, j - m + 1) + 1);
}

void solve(){

    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> g[i];

    int ans = 0, ansx = 0, ansy = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j] == '.'){
                int v = getV(i, j);
                int h = getH(i, j);
                if( v + h > ans )
                    ans = v + h, ansx=i, ansy =j;
            }
        }
    }

    cout << ansx  + 1<< " " << ansy + 1<< "\n";
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}
