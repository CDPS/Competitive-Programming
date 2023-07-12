#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){

    int n, k,m;
    cin >> n >> k;

    for(int i=0;i<k;i++){
        cin >> m;
        for(int j=m-1;j<n;j++){
            if(a[j]==0){
                a[j]=m;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}

