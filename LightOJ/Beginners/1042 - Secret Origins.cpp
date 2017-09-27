#include <stdio.h>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    int caseno=1;

    while(t){

        long long n,r=0;
        scanf("%lld",&n);
        string s;

        while( n!= 0)
        {
            int a =n%2;
            s = (char)(a + 48)+s;
            n=n/2;

        }
        s="0" + s;
        next_permutation(s.begin(), s.end());
        int p =s.size();

        for(int i=0 ; i<p;i++) {
            r+= (pow(2,(p-1)-i))*((int)(s[i]-48));
        }
        printf("Case %d: %lld\n",caseno++,r);
        t--;
    }
    return 0;
}
