#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

char p[2] = { 'a' , 'b' };

bool solve(){

    cin >> n >> s;

    string init = "";
    for(int i=0; i < n; i++)
        init += p[i%2] ;


    for(int i=0, l = 0, h = n-1; i < n; i++){

        if(s[i] == init[l]){
            l++; continue;
        }

        if(s[i] == init[h]){
            h--; continue;
        }

        if(s[i] == '?' ){

            int curr = 1;
            while( i < n && s[i] == '?')
                i++, curr++;

            if(i == n) break;

            if(init[l] == s[i])
                l++, h-= curr-1;
            else
                l+=2, h-= curr-2;

            continue;
        }

        return false;
    }

    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}
