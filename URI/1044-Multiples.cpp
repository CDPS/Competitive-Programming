#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;

    cin >> n >> m;

    if(n>m)
        swap(n,m);

    if(m%n==0)
        printf("Sao Multiplos\n");
    else
        printf("Nao sao Multiplos\n");

    return 0;
}
