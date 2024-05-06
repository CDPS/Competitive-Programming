#include <bits/stdc++.h>

using namespace std;

int a[30];
int n;

int main(){

    cin >> n;

    for(int i=0;i<n;i++)
        cin >> a[i];

    int maxi = 1;
    for(int i=0;i<n;i++){
        int j = i + 1;
        while( j < n && a[j]> a[j-1] )
            j++;
        maxi = max(j-i, maxi);
    }

    cout << maxi << "\n";
    return 0;
}

