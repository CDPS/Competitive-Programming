#include <bits/stdc++.h>

using namespace std;

const int m = 1e6 + 3;

int t = 1;

map<char, string> mp = {
    { '>' , "1000" },
    { '<' , "1001" },
    { '+' , "1010" },
    { '-' , "1011" },
    { '.' , "1100" },
    { ',' , "1101" },
    { '[' , "1110" },
    { ']' , "1111" }
};

string s, temp;

int solve(){

    cin >> temp;

    string s = "";
    for(int i=0;i < temp.size();i++)
        s+= mp[temp[i]];

    int pow = 1, ans = 0;
    for(int i=s.size()-1; i >= 0; i--){
        if(s[i]== '1')
            ans = (ans + pow)%m;
        pow = (pow * 2)%m;
    }

    return ans;
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n";

    return 0;
}
