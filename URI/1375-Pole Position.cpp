#include <bits/stdc++.h>

using namespace std;


int main(){

    int n;
    while(true){
        scanf("%d",&n);

        if(n==0)
            break;

        vector<int> a(n,0);
        for(int i=0;i<n;i++){
            int c,p;
            scanf("%d %d",&c,&p);

            if(i+p >=0 && i+p<n)
                a[i+p]=c;
        }

        int f=1;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                f=0;
                break;
            }
        }

        if(f){
             printf("%d",a[0]);
            for(int i=1;i<n;i++)
                printf(" %d",a[i]);
            printf("\n");
        }
        else
            printf("-1\n");
    }

    return 0;
}
