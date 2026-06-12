#include <bits/stdc++.h>

using namespace std;

int t = 1, n;
string s;
set<string> st = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

bool is_digits(string& str){
    return all_of(str.begin(), str.end(), ::isdigit);
}

int solve(){

    cin >> n;

    int ans = 0;
    while(n--){
        cin >> s;
        if(is_digits(s)){
            int x = stoi(s);
            ans += x<18;
        }else{
            ans+= st.count(s);
        }
    }

    return ans;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    while(t--)
        cout << solve() << "\n" ;

    return 0;
}
