#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int a[100];
int b[100];
int main() {
    int t,caseno=1;
    scanf("%d",&t);
    int c=1;
    while(t){
        int n,m,d,y,z;
        char c;
        scanf("%d %d",&n,&m);

        for(int i=0; i<n;i++){
            scanf("%d",&a[i]);
        }

        while(m){
            scanf(" %c",&c);
            if(c=='S'){
                scanf("%d",&d);
                for(int i=0; i<n;i++){
                    a[i]+=d;
                }
            }else if(c=='M'){
                scanf("%d",&d);
                for(int i=0; i<n;i++){
                    a[i]*=d;
                }
            }else if(c=='D'){
                scanf("%d",&d);
                for(int i=0; i<n;i++){
                    a[i]/=d;
                }
            }else if(c=='R'){

                for(int i=0; i<n;i++){
                    b[i]=a[(n-1)-i];
                }
                swap(b,a);
            }else{

                scanf("%d %d",&y,&z);
                swap(a[y],a[z]);
            }
            m--;
        }
        printf("Case %d:\n",caseno++);
        for(int i=0; i<n-1;i++){
            printf("%d ",a[i]);
        }
            printf("%d\n",a[n-1]);
        t--;
    }

    return 0;
}
