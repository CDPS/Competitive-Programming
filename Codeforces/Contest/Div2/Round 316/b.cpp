#include <bits/stdc++.h>

using namespace std;

int main(){
    long n,m;

    scanf("%ld %ld",&n,&m);

    if(n==1){printf("1\n");}
    else if( abs(n-m) >= m){
        printf("%d\n",m+1);
    }
    else {
        printf("%d\n",m-1);
    }
    return 0;
}
