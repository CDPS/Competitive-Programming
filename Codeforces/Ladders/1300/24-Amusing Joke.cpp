#include <bits/stdc++.h>

using namespace std;

int main(){

    string a,b,c;

    cin >> a >> b >> c;

    string d= a +b;

    sort(d.begin(),d.end());

    sort(c.begin(),c.end());

    if(c.length() > d.length() ||   c.length() < d.length() ){
        cout << "NO\n";
    }else{
        bool t=true;
        for(int i=0;i<d.length();i++)
            if(d[i]!=c[i]){ t=false; break; }

        cout << ( (t)? "YES\n":"NO\n"  );
    }
    return 0;
}
