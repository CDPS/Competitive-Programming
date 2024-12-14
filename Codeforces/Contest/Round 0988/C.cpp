#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n;
    cin >> t;

    while(t--){

       cin >> n;

       if(n<5){
          cout << "-1" << "\n";
          continue;
       }

       for(int i=2;i<=n;i+=2)
          if(i!=4)
            cout << i << " ";

       cout << "4 5";

       for(int i=1;i<=n;i+=2)
          if(i!=5)
            cout << " " << i;

       cout << "\n";
    }
    return 0;
}
