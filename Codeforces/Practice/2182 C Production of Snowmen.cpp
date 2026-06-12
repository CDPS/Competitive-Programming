#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

bool check(vector<int> &a, vector<int> &b, int d){
    for(int i=0;i<n;i++)
        if( a[i] >= b[ (i+d) %n])
            return false;
    return true;
}

ll solve(){

    cin >> n;

    vector<int> a(n), b(n), c(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> c[i];

    int part1 = 0, part2 = 0;
    for(int i=0;i < n;i++){
        part1+= check(a, b, i);
        part2+= check(b, c, i);
    }

    return 1ll*part1*part2*n;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
