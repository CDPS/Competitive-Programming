#include <bits/stdc++.h>

using namespace std;

int t = 1;
string s;

int solve(){

    cin >> s;

    int count_4 = 0, count_7 = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '4') count_4++;
        if(s[i] == '7') count_7++;
    }

    if(count_4 == 0 && count_7 == 0)
        return -1;

    return count_4 >= count_7? 4 : 7;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
