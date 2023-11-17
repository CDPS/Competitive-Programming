#include <bits/stdc++.h>

using namespace std;

int a[5], b[5];

int main(){

    while(cin >> a[0] >> a[1] >> a[2]>> a[3]>> a[4]){
          cin >> b[0] >> b[1] >> b[2]>> b[3]>> b[4];

        if( a[0] + b[0] == 1 &&
            a[1] + b[1] == 1 &&
            a[2] + b[2] == 1 &&
            a[3] + b[3] == 1 &&
            a[4] + b[4] == 1 )
                cout << "Y" << "\n";
        else
            cout << "N" << "\n";
    }
    return 0;
}
