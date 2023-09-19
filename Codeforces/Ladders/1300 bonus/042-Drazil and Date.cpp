#include <bits/stdc++.h>

using namespace std;

int main(){

    int a,b,s;

    cin >> a >> b >> s;

    a = (a<0)? a*-1 : a;
    b = (b<0)? b*-1 : b;
    int d = a + b;

    if(s < d ){
        cout << "No" << "\n";
    }
    else{
        s -= d;
        cout <<   ((s%2)? "No" : "Yes") << "\n";
    }
    return 0;
}
