#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){

    cin >> n;

    vector<int> freq(3, 0);
    for(int i=0; i < n; i++)
        cin >> x, freq[x]++;

    int mini = min(freq[1], freq[2]);

    freq[1] -= mini;
    freq[2] -= mini;

    return freq[0] + mini + (freq[1]/3) + + (freq[2]/3);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
