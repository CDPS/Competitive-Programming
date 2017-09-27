#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){
    int n;
    cin >> n;
    int aux;
    int total =0;

    for(int i=0;i<n;i++){
        cin >> aux;
        total+=aux;
    }

    int res=0;
    for(int i=1;i<=5;i++)
        if( (total+i)%(n+1)!=1)res++;
    cout << res << "\n";
    return 0;
}
