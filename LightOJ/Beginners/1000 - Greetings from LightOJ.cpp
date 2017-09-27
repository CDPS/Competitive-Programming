#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases;
    scanf("%d",&cases);
    int c=1;
    while(cases){
        int a;
        scanf("%d",&a);

        int b;
        scanf("%d",&b);

        printf("Case %d: %d\n",c,a+b);
        cases--;
        c++;
    }
    return 0;
}
