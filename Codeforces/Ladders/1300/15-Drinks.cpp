#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d",&n);
    int acc =0,aux;

    for(int i=0;i<n;i++){
        scanf("%d",&aux);
        acc+=aux;
    }

    printf("%lf", (double)acc/(double)n);
    return 0;
}
