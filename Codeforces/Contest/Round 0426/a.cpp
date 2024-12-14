#include <bits/stdc++.h>

using namespace std;

int main(){

    map<char,long > mp; mp['v']=0; mp['<']=1; mp['^']=2; mp['>']=3;

    char a,b;long n;
    cin >> a >> b;
    cin >> n;

    long ac = mp[a],bc = mp[b];
    int r1 = (ac+n)%4,r2 = (bc+n)%4;

    if( r1==bc && r2==ac ) cout << "undefined\n";
    else if( r1 == bc)     cout << "cw\n";
    else                   cout << "ccw\n";
    return 0;
}
