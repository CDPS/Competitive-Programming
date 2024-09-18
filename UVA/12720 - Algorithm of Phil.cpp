#include <bits/stdc++.h>

using namespace std;

int m = 1000000007;

int solve(string s){

    int  n = s.size();
    int  p = 1;
    int ans = 0;
    int l, r, b;
    r = n / 2, l = r - 1;
    for(int i = 0, j = n&1; i < n; i++, j = !j) {
        if(j) {
            if(n - r > l) b = (s[r] - '0'), r++;
            else b = (s[l] - '0'), l--;
        } else {
            if(s[l] > s[r]) b = (s[l] - '0'), l--;
            else b = (s[r] - '0'), r++;
        }
        if(b)
            ans = ( (ans%m) + (p)%m )%m;
        p = ( (p%m) *2 )%m;
    }
    return ans;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        cout << solve(a)<< "\n";
    }
    return 0;
}
