#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){

    int n,m,x,y;
    cin >> n;

    for(int i=0;i<n;i++)
       cin >> a[i];

    cin >> m ;

    for(int i=0;i<m;i++){
        cin >> x >> y;
        x--;
        int temp = a[x];
        a[x] = 0;

        if(x == n-1){
            a[x-1]+= y-1;
        }
        else if(x==0){
            a[x+1]+= temp - y;
        }
        else{
            a[x-1]+= y-1;
            a[x+1]+= temp - y;
        }
    }

    for(int i=0;i<n;i++)
        cout << a[i] << "\n";
    return 0;
}

