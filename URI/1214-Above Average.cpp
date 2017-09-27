#include <bits/stdc++.h>

using namespace std;

int a[1000];

int main(){

    int c;
    scanf("%d",&c);

    while(c--){

        int n;
        scanf("%d",&n);
        int ac=0;

        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            ac+=a[i];
        }

        int pro= ac/n;
        ac=0;
        for(int i=0;i<n;i++){
            if(a[i]>pro) ac++;
        }

        double res= (double)(ac)/(double)(n);

        res*=100;
        printf("%.3f%\n",res);
    }
    return 0;
}
