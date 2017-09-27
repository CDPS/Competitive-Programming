
#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",a+i);


    int l=0,r=n-1; int c;
    bool f=1;

    for(int i=1;i<n;i++){
        if(a[l]>a[i]){
        break;
        }
        l=i;
    }

    for(int i=n-2;i>=0;i--){
        if( a[r] < a[i]){
          break;
        }
        r=i;
    }
    if(r==0 && l==n-1){
        printf("yes\n1 1");
        return 0;
    }

    reverse(a+l, a+r+1);
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
           printf("no\n");
           return 0;
        }
    }
    printf("yes\n%d %d",l+1,r+1);
    return 0;
}
