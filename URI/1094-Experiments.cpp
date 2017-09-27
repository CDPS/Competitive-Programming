#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d",&n);
    int ar[3]={0,0,0};
    int total=0;
    for(int i=0;i<n;i++){
        char a; int c;
        cin >> c >> a;

        if(a=='C')
            ar[0]+=c;
        else if(a=='R')
            ar[1]+=c;
        else
            ar[2]+=c;

        total+=c;
    }

    printf("Total: %d cobaias\n",total);
    printf("Total de coelhos: %d\n",ar[0]);
    printf("Total de ratos: %d\n",ar[1]);
    printf("Total de sapos: %d\n",ar[2]);
    printf("Percentual de coelhos: %.2lf %%\n",( (double)ar[0]/(double)total)*100.0);
    printf("Percentual de ratos: %.2lf %%\n",((double)ar[1]/(double)total)*100.00) ;
    printf("Percentual de sapos: %.2lf %%\n",((double)ar[2]/(double)total)*100.00);

    return 0;
}
