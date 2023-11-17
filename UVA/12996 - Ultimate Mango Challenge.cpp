#include <bits/stdc++.h>

using namespace std;

int a[10];
int b[10];

int main(){

    int t, caseno = 1,n,l;

    cin >> t;

    while(t--){

        cin >> n >> l;

        int acc = 0;
        bool ans = true;

        for(int i=0;i<n;i++)
            cin >> a[i], acc += a[i];

        for(int i=0;i<n;i++)
            cin >> b[i], ans &= b[i] >= a[i];

        cout << "Case "<< caseno++ << ": " <<( (ans && acc <= l  )? "Yes" : "No" ) << "\n";
    }
    return 0;
}
