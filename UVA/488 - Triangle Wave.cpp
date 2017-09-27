#include <bits/stdc++.h>

using namespace std;

int main(){

    int t,a,f;
    cin >> t;

    int first =1,second;
    while(t--){
        cin >> a >> f;

        if(!first) cout << "\n";
        first=0;
        second=1;
        while(f--){
            if(!second) cout << "\n";
            second=0;

            for(int i=1;i<=a;i++){
                for(int j=0;j<i;j++)
                    cout << i;
                cout << "\n";
            }

            for(int i=a-1;i>0;i--){
                for(int j=0;j<i;j++)
                    cout << i;
                cout << "\n";
            }

        }

    }
    return 0;
}
