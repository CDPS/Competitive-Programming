#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

int t, n;
string s;

ll sol(char c){

    vector<int> pos;
    for(int i=0;i<n;i++)
        if(s[i]==c)
            pos.push_back(i);

    if(pos.size() == 0)
        return n + 1;

    int mid = pos.size()/2;

    ll ans = 0,acc = 0;
    for(int i= mid; i< pos.size();i++)
        ans+= pos[i] - pos[mid] - acc, acc++;

    acc=0;
    for(int i = mid; i>= 0;i--)
        ans+= pos[mid] - pos[i] - acc, acc++;

    return ans;
}

ll solve(){
    cin >> n >> s;
    return min({sol('a'), sol('b')});
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << solve() << "\n";

    return 0;
}
