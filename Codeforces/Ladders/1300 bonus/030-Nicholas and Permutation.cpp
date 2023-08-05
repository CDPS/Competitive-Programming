#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){

    int n, index1, indexN;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==1)
            index1 = i;
        if(a[i]==n)
            indexN = i;
    }
    cout << max(  max( index1+1, indexN+1 ), max( abs(n-index1), abs(n-indexN))) - 1 <<  "\n";
    return 0;
}
