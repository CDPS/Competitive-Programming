#include <bits/stdc++.h>

using namespace std;

int t, n , k;
string s;

char a[2] = {'1', '0'};

bool solve(){

    cin  >> n >> k >> s;

    for(int i=0; i < n-k; i++)
        if(s[i] == '1') 
            s[i] = '0', s[i + k] = a[s[i+k]-'0'];

    for(int i = 0 ; i < n; i++)
        if(s[i] == '1') 
            return false;
    
    return true;
}

int main(){
    
    cin.sync_with_stdio(false); cin.tie(NULL);
    
    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO") << "\n";

    return 0;
}