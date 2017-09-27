#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        int div = 10;
        string s = "0.";

        while(true){
            int d = div/n;
            s+=  char(d + '0');
            div = div - (d*n);
            if(div==1)
                break;
            div*=10;
        }
        cout << s << "\n";
    }
    return 0;
}
