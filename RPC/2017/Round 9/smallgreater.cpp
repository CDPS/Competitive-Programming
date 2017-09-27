#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

long long next(long long m, int k) {

	long long ans, ks = (1LL<<k);
	int bits = (log(m)/log(2) +1);
	ks--;
	if(bits < k){
        ans = ks;
	}else{

        long long mini = m | ks;
        int bitsks = (log(ks)/log(2) +1);
        long long n = m;
        int j=0;
        while(bitsks<=bits){
            if(m|ks>n) mini = min(mini, m | ks);
            m = m & ~(1<<j);
            ks = (ks << 1ll);
            bitsks++;
            j++;
        }
        ans = mini;
	}
	return ans;
}

int main () {

 	long long m; int k;
	while(scanf("%lld %d", &m, &k)==2){
        printf("%lld\n", next(m, k));
    }
	return 0;
}
