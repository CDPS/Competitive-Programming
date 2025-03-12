#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, k;

    cin >> t;
    while(t--){

        cin >> n >> k;

        int maxi = n/2 - !(n%2);

        if(k>maxi){
            cout << -1 << "\n"; continue;
        }

        memset(a, 0, sizeof  a);
        for(int i=0,j=1;i<k; i++, j+=2)
            a[j]= n-i;

        for(int i=0,j=1;i<n;i++)
            if(a[i]==0) a[i]= j++;

        for(int i=0;i<n;i++)
            cout << a[i] << " \n"[i==n-1];
    }
    return 0;
}
