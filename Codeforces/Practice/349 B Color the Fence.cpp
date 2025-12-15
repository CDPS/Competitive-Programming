#include <bits/stdc++.h>

using namespace std;

int a[10];
int k;

string solve(){

    cin >> k;

    int maxi= 0, d = 0, curr = 1e9;
    for(int i=1;i<=9;i++){
        cin >> a[i];
        if(k/a[i] > maxi ){
            maxi = k/a[i], d = i, curr = a[i];
        }
    }

    if(maxi == 0)
        return "-1";

    string ans = "";
    while(maxi--)
        ans+= char('0' + d), k-= curr;

    for(int i=0;i<ans.size();i++){
        for(int j=9; j>=1; j--){
            if(  (k + curr) - a[j] >= 0 ){
                ans[i] = char('0' + j );
                k += curr - a[j];
                break;
            }
        }
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << "\n";

    return 0;
}
