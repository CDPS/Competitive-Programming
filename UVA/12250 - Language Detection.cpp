#include <bits/stdc++.h>

using namespace std;

int main(){

    map< string, string> mp;
    mp["HELLO"]       = "ENGLISH";
    mp["HOLA"]        ="SPANISH";
    mp["HALLO"]       ="GERMAN";
    mp["BONJOUR"]     ="FRENCH";
    mp["CIAO"]        ="ITALIAN";
    mp["ZDRAVSTVUJTE"]="RUSSIAN";

    int caseno=1; string s;

    while(cin >> s && s!="#")
        cout << "Case " << caseno++ << ": "<< (mp[s]==""? "UNKNOWN": mp[s]) << "\n";

    return 0;
}
