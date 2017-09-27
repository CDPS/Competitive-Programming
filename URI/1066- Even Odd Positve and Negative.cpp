#include <bits/stdc++.h>

using namespace std;

int main(){

    int a;
    int odd=0,even=0,neg=0, pos=0;
    for(int i=0;i<5;i++){
        cin >> a;
        if(a%2)
            odd++;
        else
            even++;

        if(a==0)
            continue;
        else if( a>0)
            pos++;
        else
            neg++;
    }

    printf("%d valor(es) par(es)\n",even);
    printf("%d valor(es) impar(es)\n",odd);
    printf("%d valor(es) positivo(s)\n",pos);
    printf("%d valor(es) negativo(s)\n",neg);
    return 0;
}
