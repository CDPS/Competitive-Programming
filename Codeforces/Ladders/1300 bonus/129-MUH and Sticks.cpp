#include <bits/stdc++.h>

using namespace std;

int main(){


    map<int, int> mp;
    int x;
    bool ok = false;

    for(int i =0;i<6;i++){
        cin >> x;
        mp[x]++;
        if(mp[x]==4)
            mp.erase(x), ok = true;
    }

    if(ok){ cout << ( (mp.size()== 1)? "Elephant" : "Bear"  ) << "\n"; }
    else{ cout << "Alien" << "\n"; }

    return 0;
}
