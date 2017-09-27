#include  <bits/stdc++.h>

using namespace std;


int main(){
    double a=0;
    double av=0;
    int res=0;
    for(int i=0;i<6;i++){
        cin>> a;
        if(a>0.0){
            res++;
            av+=a;
        }

    }

    printf("%d valores positivos\n",res);
    printf("%.1lf\n",av/res);
    return 0;
}
