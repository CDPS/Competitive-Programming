#include <bits/stdc++.h>

using namespace std;

int a[30];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t,n,x;
    cin >> t;

    while(t--){

        memset(a,0, sizeof a);

        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x;
            for(int j=29;j>=0;j--)
                a[j] += (( x&(1<<j) )!= 0);
        }

        int k = 0;
        for(int i=0;i<30;i++)
            k = (a[i]!=0)? __gcd(a[i], k) : k;

        if(k==0){
            for(int i=1; i<= n; i++)
                cout << i << " \n"[i==n];
            continue;
        }

        for(int i=1; i<=k; i++) {
            if(k%i == 0) cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}
