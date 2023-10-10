#include <bits/stdc++.h>

using namespace std;

int a[3000];
map<int,int> mp;

int main(){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[ a[i] ]++;
    }

    int res =0;
    for(int i=0;i<n;i++){
       if(mp[ a[i] ] !=1 ){
            int x = a[i];
            while( mp[ x ] !=0 ){
                x++;
                res++;
            }
            mp[ a[i] ]--;
            mp[ x ]++;
       }
    }

    cout << res << "\n";
    return 0;
}

