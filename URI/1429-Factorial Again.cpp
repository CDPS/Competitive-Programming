#include <bits/stdc++.h>

using namespace std;


int main(){

    int n;
    int fact[5] = {1,2,6,24,120};
    scanf("%d",&n);



    while(n!=0){
        long res=0;
        int i=0;
        while(n>0){
            res+= (n%10) *fact[i];
            n/=10;
            i++;
        }

        printf("%ld\n",res);
        scanf("%d",&n);
    }

    return 0;
}
