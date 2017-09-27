#include <bits/stdc++.h>

using namespace std;

int a[1000];

int main(){

    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        int acc=0;
        for(int i=0;i<n;i++)
            cin >> a[i], acc+=a[i];
        int avg = acc/n;
        int p=0;
        for(int i=0;i<n;i++){
            if(a[i]>avg)p++;
        }
        cout << fixed << setprecision(3) << double(p)/double(n)*100.0 << "%\n";
    }
    return 0;
}
