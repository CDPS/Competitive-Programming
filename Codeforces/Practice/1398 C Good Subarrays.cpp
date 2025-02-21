#include <bits/stdc++.h>

using namespace std;

int t,n;
string s;

long long solve(){
    map<long long, int> mp = {{0, 1}};

    long long sum = 0, ans = 0;
    for(int i=0;i<n;i++){
        sum += (s[i]-'0');
        ans += mp[sum - (i + 1) ] ;
        mp[sum - (i + 1) ]++;
    }
    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n >> s;
        cout << solve() << "\n";
    }
    return 0;
}
