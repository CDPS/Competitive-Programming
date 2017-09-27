#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    scanf("%d",&n);
    while(n!=0){

        int res=0;
        while(n!=1){
            int groups= n/3;

            if(n%3)
                groups++;

            n=groups;
            res+=groups;
        }

        printf("%d\n",res);
        scanf("%d",&n);
    }
    return 0;
}
