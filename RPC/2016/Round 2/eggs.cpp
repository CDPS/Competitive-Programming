#include <bits/stdc++.h>


using namespace std;

bool m[1000001];
int ps[1000001];
int memo[1000001];

void criba(int tam){
	    m[0] = false;
	    m[1] = true;
	    ps[0]=0;
	    ps[1]=1;

	    for(int i = 2; i <= tam; ++i)
	        m[i] = true;

	    for (int i = 2; i <= tam; ++i) {
	        if (m[i]) {
	        	ps[i]=i;
	          for (int j = i; j <=tam; j += i) {
	            ps[j] = i;
	             m[j]=false;
	          }
	        }
	      }
}

int main(){

    int n;
    memset(memo,0,sizeof memo);
    criba(1000000);

    while(scanf("%d",&n)==1){

        int res=0;
        if(m[n]){
            printf("1\n");
        }
        else{
            int mi=n;
            while(n>0){
                if(memo[n]==0){
                    n-=ps[n];
                    res++;
                }else{
                    res+=memo[n];
                    break;
                }
            }
            memo[mi]=res;
            printf("%d\n",res);
        }
    }

    return 0;
}
