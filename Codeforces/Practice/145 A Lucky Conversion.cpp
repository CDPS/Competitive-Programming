#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
string a, b;

int freq[2][8];

int solve(){

    cin >> a >> b;  n = a.size();

    for(int i=0;i<n;i++){
        freq[0][a[i]-'0']++;
        freq[1][b[i]-'0']++;
    }

    if(freq[1][7]  < freq[0][7] ){
        swap(a, b);
        swap(freq[0][4], freq[1][4]);
        swap(freq[0][7], freq[1][7]);
    }

    int ans = 0;
    int diff = freq[1][7]- freq[0][7];
    for(int i=0; diff > 0 && i<n;i++){
        if(a[i] == '4' && b[i] == '7')
            diff--, a[i] = '7', ans++;
    }

    int curr = 0;
    for(int i=0; i<n;i++)
        if(a[i] != b[i] )
            curr++;

    return ans + (curr/2);

}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
