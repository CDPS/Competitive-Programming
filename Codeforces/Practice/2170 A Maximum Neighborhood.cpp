#include <bits/stdc++.h>

using namespace std;

int t, n;

int xs[4] = {1, -1, 0, 0};
int ys[4] = {0,  0, 1, -1};


bool valid(int x, int y){
    return x >= 0 && x < n && y >=0 && y < n;
}

int solve(){

    cin >> n ;

    vector< vector<int> > a(n, vector<int>(n));
    for(int i=0, curr = 1;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j] = curr++;

    int ans  = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int curr = a[i][j];
            for(int k=0;k<4;k++){
                int vx = i + xs[k], vy = j + ys[k];
                if(valid(vx, vy))
                    curr+= a[vx][vy];
            }
            ans = max(curr, ans);
        }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}

