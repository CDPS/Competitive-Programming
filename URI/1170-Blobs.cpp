#include <bits/stdc++.h>

using namespace std;

int main(){


    int t;

    scanf("%d",&t);

    while(t--){

        double s;
        scanf("%lf",&s);

        int res=0;

        while(s > 1.0){
             s/=2;
             res++;
        }

        printf("%d dias\n",res);

    }

    return 0;
}
