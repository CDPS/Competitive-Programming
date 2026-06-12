#include <bits/stdc++.h>

using namespace std;

int t =1;
string s;

bool solve(){

    cin >> s;

    int n = s.size();

    int mini_a = 1e9, maxi_a = -1;
    int mini_b = 1e9, maxi_b = -1;
    int mini_c = 1e9, maxi_c = -1;
    for(int i=0; i < n ; i++){

        if(s[i] != 'a' && s[i] != 'b' && s[i] != 'c')
            return false;

        if(s[i] == 'a'){
            mini_a = min(mini_a, i);
            maxi_a = max(maxi_a, i);
        }

        if(s[i] == 'b'){
            mini_b = min(mini_b, i);
            maxi_b = max(maxi_b, i);
        }

        if(s[i] == 'c'){
            mini_c = min(mini_c, i);
            maxi_c = max(maxi_c, i);
        }
    }

    if(mini_c == 1e9) return false;

    if(mini_a != 0) return false;

    if(mini_b != maxi_a + 1) return false;

    if(mini_c != maxi_b + 1) return false;

    if(maxi_c != n - 1) return false;

    for(int i=mini_a; i <= maxi_a; i++)
        if(s[i] != 'a' ) return false;
    for(int i=mini_b; i <= maxi_b; i++)
        if(s[i] != 'b' ) return false;
    for(int i=mini_c; i <= maxi_c; i++)
        if(s[i] != 'c' ) return false;


    return maxi_c - mini_c == maxi_a-mini_a || maxi_c - mini_c  == maxi_b - mini_b;
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    while(t--)
        cout << ( solve()? "YES" : "NO")  << "\n" ;

    return 0;
}
