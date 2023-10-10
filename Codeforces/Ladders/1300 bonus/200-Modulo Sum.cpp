#include <bits/stdc++.h>

using namespace std;

long long a[1000000];

int main(){

    int n,m;
    cin >> n >> m;
    cin >> a[0];
    for(int i=1;i<n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }

    bool res = false;
    for(int i=0;i<n && !res ;i++){
        res = a[i]%m==0;
        if(res) break;
        res = (a[n-1]-a[i])%m==0;
    }

    if(!res){
        int i=0, j=n-1;
        do{
            res = a[j]-a[i])%m==0;
            i++; j--;
        }while(i <= j  )
    }

    return 0;
}
