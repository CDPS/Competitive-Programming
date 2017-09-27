#include <bits/stdc++.h>

using namespace std;

int a[13];

int main(){

    int n;
    bool first=1;
    while(scanf("%d",&n) && n!=0){

        for(int i=0;i<n;i++)
            scanf("%d",a+i);

        if(!first)printf("\n");
        first=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
                    for(int l=k+1;l<n;l++)
                        for(int m=l+1;m<n;m++)
                            for(int nn=m+1;nn<n;nn++)
                                 printf("%d %d %d %d %d %d\n",a[i],a[j],a[k],a[l],a[m],a[nn]);
    }
    return 0;
}
