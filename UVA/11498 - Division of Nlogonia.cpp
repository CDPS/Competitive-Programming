#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);
    int n,dx,dy,x,y;

    while(cin >> n && n){
        cin >> dx >> dy;
        while(n--){
        cin >> x >> y;
        if(x==dx || y==dy)
            cout << "divisa\n";
        else if(x>dx&&y>dy)
            cout << "NE\n";
        else if(x>dx && y<dy)
            cout << "SE\n";
        else if(x<dx && y> dy)
            cout << "NO\n";
        else
            cout << "SO\n";
        }
    }
    return 0;
}
