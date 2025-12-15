#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;

string s[2];

bool checkPath(int i){
    for(int j=0;j<n;j++){
        if(s[i][j]  == 'W' ) return false;
        if(s[!i][j] == 'B' ) i = !i;
   }
   return true;
}

bool solve(){
    cin >> n >> s[0] >> s[1];
    return checkPath(0) || checkPath(1);
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n" ;

    return 0;
}
