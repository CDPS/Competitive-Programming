#include <bits/stdc++.h>

using namespace std;

int a[20];
int main(){

    int t,n;
    cin >> t;

    while(t--){
        cin >> n;
        int acc =0,pos,ans=0 ;
        for(int i=0;i<n;i++)
            cin >> a[i], acc+=a[i];
       sort(a,a+n);
       pos = acc/n;
       ans =((pos-a[0])*2) + ( (a[n-1]-pos)*2);
       cout << ans << "\n";
    }
    return 0;
}
