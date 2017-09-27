#include <bits/stdc++.h>

using namespace std;

int main(){
    long t,a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a > b)
            cout << ">\n";
        if(a < b)
            cout << "<\n";
        if(a==b)
            cout << "=\n";
    }
    return 0;
}
