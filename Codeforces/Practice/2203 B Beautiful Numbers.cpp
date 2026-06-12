#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
string x;

int f(string s){
    int ans = 0;
    for(int i=0;i<s.size();i++)
        ans+= s[i] - '0';
    return ans;
}

ll solve(){

    cin >> x;

    if(f(x) == f( to_string(f(x))) )
        return 0;

    sort(x.begin() + 1, x.end() );

    int curr = x[0] - '0', acc1 = 1;
    for(int i=1;i<x.size();i++){
        int curr_digit = x[i] - '0';
        if(curr_digit + curr > 9)
            break;
        acc1++;
        curr+= curr_digit;
    }

    curr = 0;
    int acc2 = 0;
    for(int i=1;i<x.size();i++){
        int curr_digit = x[i] - '0';
        if(curr_digit + curr >= 9)
            break;
        acc2++;
        curr+= curr_digit;
    }

    return min (x.size() - acc1, x.size() -acc2) ;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}

