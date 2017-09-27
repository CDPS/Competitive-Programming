#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,s,d;
    cin >> t;

    while(t--){
        cin >> s >> d;
        if(d>s || (s-d)%2)
            cout << "impossible\n";
        else
            cout << (s- ( (s-d)/2) ) << " " << (s-d)/2 << "\n";
    }
    return 0;
}
