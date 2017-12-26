#include <bits/stdc++.h>

using namespace std;


int lucky[14]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};

int main(){
    int n;
    scanf("%d",&n);

    bool f=false;
    for(int i=0;i<14;i++)
        if(n==lucky[i]||n%lucky[i]==0)f=true;
    printf("%s\n",(f)?"YES":"NO");
    return 0;
}
