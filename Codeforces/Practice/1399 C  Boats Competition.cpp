#include <bits/stdc++.h>

using namespace std;

int t, n, x;

int solve(){

    cin >> n;

    vector<int> freq(201, 0);
    for(int i=0; i<n; i++)
        cin >> x, freq[x]++;

    int ans = 0;
    for(int i=100; i >= 1; i--){

        int curr_pairs = 0;
        for(int j = 1; j <= i/2; j ++){
            int t = i - j;
            if(t == j){
                curr_pairs+= freq[t]/2;
            }else{
                curr_pairs+= min(freq[j], freq[t]);
            }
        }
        ans = max( ans, curr_pairs);
    }

    return ans;
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
