#include <bits/stdc++.h>

using namespace std;

int t, n;
int acc[2];
string a, b;

bool solve(){

    cin >> n >> a >> b;

    acc[0] = acc[1] = 0;

    for(int i=0;i<n;i++)
        acc[ a[i]-'0']++;

    int changes = 0;

    for(int i=n-1;i>=0;i--){

        if(a[i]!=b[i] && changes%2==0 && acc[0]!=acc[1])
            return false;

        if(a[i]==b[i] && changes%2  &&  acc[0]!=acc[1] )
            return false;

        if(a[i]!=b[i] && changes%2==0 && acc[0]==acc[1] )
            changes++;

        if(a[i]==b[i] && changes%2  && acc[0]==acc[1] )
            changes++;

        acc[ a[i]-'0']--;
    }

    return true;
}

int main(){


    cin.sync_with_stdio(false); cin.tie(NULL);

    cin >> t;
    while(t--)
        cout << (solve()? "YES" : "NO" ) << "\n";

    return 0;
}

