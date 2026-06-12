#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int freq[10];

bool check(int m) {

    if (4LL * m > n) return false;
    int S01 = freq[0] + freq[1];
    int S05 = freq[0] + freq[1] + freq[2] + freq[3] + freq[4] + freq[5];

    int _floor = max(0, m - freq[0]);
    int _ceil  = min({m, freq[1], S01 - m, S05 - 2 * m});

    return _floor <= _ceil;
}

int solve(){

    cin >> n >> s;

    memset(freq, 0, sizeof(freq));
    for(int i=0;i < n; i++)
        freq[s[i]-'0']++;

    int ans = 0;
    for(int i=1; i<= n; i++)
        if(check(i))
            ans = i;

    return ans;
}

int t;
int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
