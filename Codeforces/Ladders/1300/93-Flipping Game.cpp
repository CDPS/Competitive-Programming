#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){

    int n;
    scanf("%d",&n);

    int ones =0;
    for(int i=0;i<n;i++)
        scanf("%d",a+i), ones = (a[i]==1)? ones+1:ones;

    int maxi=0;
    for(int i=0;i<n;i++){
        int o=0,z=0;
        for(int j=i;j<n;j++){
            if(a[j]) o++;
            else z++;
            maxi = max(maxi,  (ones-o)+z );
        }
        printf("\n");
    }
    printf("%d",maxi);
    return 0;
}
