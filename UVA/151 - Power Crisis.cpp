#include <bits/stdc++.h>

using namespace std;

int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    return (josephus(n - 1, k) + k-1) % n + 1;
}

int main(){
    int n;
    while( scanf("%d",&n) && n ){
        for(int i=1;i<n;i++){
            if(josephus(n-1,i)+1==13){
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
