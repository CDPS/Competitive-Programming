#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

ll a[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n;
    cin >> t;

    while(t--){

        cin >> n;

        ll sump = 0, sumn =0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]>0) sump+= a[i];
            if(a[i]<0) sumn+= (a[i]*-1);
        }


        ll maxi = 0, accp = 0,accn = sumn;
        for(int i=0;i<n;i++){
            if(a[i]>0) accp+= a[i];
            if(a[i]<0) maxi = max(maxi,accp + accn ), accn+= a[i];
        }
        maxi = max(maxi, accp);

        accp = sump , accn =0;
        for(int i=n;i >=0;i--){
            if(a[i]<0) accn+= a[i];
            if(a[i]>0) maxi = max(maxi,accp + accn ), accp-= a[i];
        }
        maxi = max(maxi, accn);

        cout << maxi << "\n";
    }
    return 0;
}
