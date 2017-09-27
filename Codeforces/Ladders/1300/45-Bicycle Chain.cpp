#include <bits/stdc++.h>

using namespace std;

int a[50];
int b[50];

int main(){
    int n,m;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    scanf("%d",&m);

    for(int i=0;i<m;i++)
        scanf("%d",b+i);

    int maxi=-1;
    int cant=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[j]%a[i]==0 && b[j]/a[i] > maxi){
                cant=1;
                maxi= (b[j]/a[i])   ;
            }
            else if( (b[j]%a[i])==0 && (b[j]/a[i])== maxi)cant++;
        }
    }

    printf("%d\n",cant);
    return 0;
}
