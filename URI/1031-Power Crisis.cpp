#include <bits/stdc++.h>

using namespace std;


int josephus(int n, int k)
{
  if (n == 1)
    return 1;

    return (josephus(n - 1, k) + k-1) % n + 1;
}

int main(){

    int n;
    while(true){
        scanf("%d",&n);

        if(n==0)
            break;
        int i=1;

        for(;i<=4*n;i++){

            int r = josephus(n-1,i) +1;

            if(r==13)
                break;
        }
        printf("%d\n",i);
    }
    return 0;
}
