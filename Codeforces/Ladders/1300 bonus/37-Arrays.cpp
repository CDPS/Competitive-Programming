#include <bits/stdc++.h>

using namespace std;

int a[100000];
int b[100000];

int main(){

    int na, nb, k, m;

    cin >> na >> nb;
    cin >> k >> m;

    for(int i =0;i<na;i++)
        cin >> a[i];

    for(int i =0;i<nb;i++)
        cin >> b[i];

    cout <<( ( a[k-1] < b[nb-m ] )? "YES"  : "NO" )<< "\n";
    return 0;
}
