#include <bits/stdc++.h>

using namespace std;

int main(){

    int answer = 0, n;
    string a, b;

    cin >> n ;
    cin >> a;
    cin >> b;

    for(int i=0; i< n;i++){
       int na = a[i]-'0';
       int nb = b[i]-'0';
       answer+= min( abs( nb-na ), min(na,nb) + 10 - max(nb,na) );
    }
    cout << answer << "\n";
    return 0;
}
