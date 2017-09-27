#include <bits/stdc++.h>

using namespace std;


int a[51];
int b[51];

int main(){

    int n,l;
    scanf("%d %d",&n,&l);

    for(int i=0;i<n;i++)
        scanf("%d", a+i);

    for(int i=0;i<n;i++)
        scanf("%d", b+i);

    if(n==1){
        printf("YES\n");
    }else{

        if(b[1]-b[0]== a[1]-a[0])
            swap(a,b);

        bool f=1;
        int d1;

        if(a[0]!=0)
         d1 = l - a[n-1] + a[0];
        else
         d1=0+a[1];


        int d2 =  b[1]-b[0];

        if(d1!=d2){
            printf("NO\n");
            return 0;
        }

        for(int i=1;i<n-1;i++){
            int d1 = a[i]- a[i-1];
            int d2 = b[i+1]-b[i];
            if(d1!=d2){
                printf("NO\n");
                return 0;
            }
        }

        d1 =  a[n-1] - a[n-2];
        d2 = l - b[n-1] + b[0];
        if(d1!=d2){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
