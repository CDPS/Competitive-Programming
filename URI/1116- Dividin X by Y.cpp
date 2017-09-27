#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        int a,b;
        cin >> a >>b;

        if(b!=0)
            printf("%.1lf\n",(double)a/(double)b);
        else
            printf("divisao impossivel\n");
    }
    return 0;
}
