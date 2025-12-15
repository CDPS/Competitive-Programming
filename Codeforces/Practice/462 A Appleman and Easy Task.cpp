#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
string a[100];

int xs[4] = {1, -1, 0, 0};
int ys[4] = {0,  0, 1, -1};

bool valid(int x, int y){
    return x >= 0 && x < n && y >=0 && y < n && a[x][y] == 'o';
}

bool solve(){

    cin >> n ;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int curr = 0;
            for(int k=0;k<4;k++)
               curr += valid(i + xs[k], j + ys[k]);
            if(curr%2) return false;
        }

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cout << ( solve() ? "YES" : "NO" ) << "\n";

    return 0;
}
