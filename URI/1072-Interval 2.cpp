#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    scanf("%d",&n);

    int a;
    int in=0;
    int out =0;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a>=10 && a<=20)
            in++;
        else
            out++;
    }

    printf("%d in\n",in);
    printf("%d out\n",out);
    return 0;

}
