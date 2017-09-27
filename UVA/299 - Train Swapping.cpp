#include <bits/stdc++.h>

using namespace std;

int a[50];
int indexs[51];

int main(){

    int t,n;
    scanf("%d",&t);

    while(t--){

        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d", a+i);
            indexs[ a[i] ] = i;
         }
        int res =0;

        for(int i=0;i<n;i++){
            if(i+1 != a[i]){
                for(int j = indexs[ i + 1 ]; j>i;j--){
                        swap(a[j],a[j-1]);
                        swap(indexs[a[j]] , indexs[a[j-1]]);
                        res++;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n",res);

    }
    return 0;
}
