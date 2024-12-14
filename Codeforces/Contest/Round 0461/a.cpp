#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    cin >> a  >> b;

    int y = b-1;

    if(a==0 && b == 1) cout << "Yes\n";
    else if(y <= a &&  (a-y)%2==0 && b >1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
