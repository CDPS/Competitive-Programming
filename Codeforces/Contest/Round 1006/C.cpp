#include <bits/stdc++.h>

using namespace std;

int a[200000];

bool check(int x, int y){
    for(int i=0;i<=30;i++)
        if((x&(1<<i))==0 && (y&(1<<i))!=0 ) return false;
    return true;
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, x ;
    cin >> t;

    while(t--){

        cin >> n >> x;

        int i=0, acc =0;;
        while(i<n && i <= x && check(x,i)) a[i] = i, acc|=a[i],i++;
        while(i<n) a[i] = x, acc|=a[i], i++;

        if(acc != x) a[n-1] = x;
        for(int j=0;j<n;j++)
            cout << a[j] << " \n"[j==n-1];
    }
    return 0;
}
