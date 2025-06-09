#include <bits/stdc++.h>

using namespace std;

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;

        if(n==2 || n%2 && n!=1 ){
            cout << "Ashishgup" << "\n";
            continue;
        }

        int even = 0;
        while(n % 2 == 0) n /= 2, even++;

        if(n==1){
            cout << "FastestFinger" << "\n";
            continue;
        }

        int odd = 0;
        for(int i = 3; i * i <= n; i += 2)
            while(n % i == 0)
                odd++, n /= i;

        if(n>1) odd++;

        cout << ( odd==1 && even==1? "FastestFinger" : "Ashishgup") << "\n";
    }

    return 0;
}
