#include <bits/stdc++.h>

using namespace std;

int t, n, k;
string s;

bool solve(){
    set<char> st; string r = "";
    for(int i=0;i<n;i++) st.insert(s[i]), r = s[i] + r ;

    if(k==0){
        return r > s;
    }
    return st.size() != 1;
}
int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);


    cin >> t;

    while(t--){
        cin >> n >> k >> s;
        cout << (solve()? "YES" : "NO") << "\n";
    }
    return 0;
}
