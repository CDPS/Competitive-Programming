#include <bits/stdc++.h>

using namespace std;

int t =1, n;
string s;

bool is_luck(){
    for(int i=0;i<n;i++)
        if(s[i] != '4' && s[i] != '7')
            return false;
    return true;
}

int getsum(int start, int target){
    int ans = 0;
    for(int i=start;i< target;i++)
        ans+= s[i] - '0';
    return ans;
}

bool solve(){

    cin >> n >> s;

    if(!is_luck()) return false;

    return getsum(0, n/2) == getsum(n/2, n);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    while(t--)
        cout << (solve()? "YES" : "NO" )  << "\n";

    return 0;
}


