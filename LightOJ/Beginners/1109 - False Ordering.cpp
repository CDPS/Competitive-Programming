#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int divs[1001];
int nums[1001];

int calcularDivisores(int n){
   int d = 0, i =1;
    while(i<=n) {
        if(n%i==0)
            d += 1;
        i++;
    }
    return d;
}

int main() {

    divs[0]=0;
    nums[0]=0;
    for(int i=1;i<=1000;i++){
        divs[i]= calcularDivisores(i);
        nums[i]=i;
    }

    int k,j,p;
    int ns = 1001;
    for(j=1;j<ns-1;j++)
    {
        p=j;
        for(k=j+1;k<ns;k++)
        {
            if(divs[k]<divs[p]){
                p = k;
            }else if (divs[k] ==divs[p] && nums[k]>nums[p]){
                p=k;
            }
        }
        if(p!=j){
            swap(nums[j],nums[p]);
            swap(divs[j],divs[p]);
        }
    }

    int t;
    scanf("%d",&t);
    int caseno=1;
    while(t){
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",caseno++,nums[n]);
        t--;
    }
    return 0;
}
