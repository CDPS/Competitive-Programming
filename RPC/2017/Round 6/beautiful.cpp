#include <bits/stdc++.h>

using namespace std;

int main() {

	int t, n, k;
	long long aux, ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &k);	
		if(k > n) k = n;
		ans = 0LL;
		for(int i = 0; i < k; i++) {
			aux = (i*6LL)+1LL;
			ans += aux;
		}
		if(n >= k) {
			n = n-k+1;
			aux = (k*6LL)+1LL;
			ans += (aux*n);
		}
		printf("%lld\n", ans);			 
	}
   	
	return 0;
}