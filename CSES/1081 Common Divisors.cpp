#include <bits/stdc++.h>

using namespace std;

int freq[1000000];

int n, x, maxi;

int solve(){
    for(int i=maxi; i>1;i--){
        int acc = 0;
        for(int j=i;j<=maxi; j+=i){
            acc += freq[j];
            if(acc >=2)
                return i;
        }
    }
    return 1;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);


    cin >> n;
    for(int i=0;i<n;i++)
        cin >> x, freq[x]++, maxi = max(maxi, x);


    cout << solve() << "\n";

    return 0;
}
