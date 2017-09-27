#include <bits/stdc++.h>

using namespace std;


bitset<100> m;

void sieve(){
   m.reset(); m.flip();
   m[0]=m[1]=0;

   for(int i=2;i*i<=100;i++){
        if(m[i]){
            for(int j=i+i;j<=100;j+=i)
                m[j]=0;
        }
   }
}
int main(){

    sieve();

    int n,k;
    cin >> n >> k;
    n++;
    int i= n;

    for(;i<m.size();i++){
        if(m[i])break;
    }

    if(i==k)printf("YES\n");
    else printf("NO\n");
    return 0;
}
