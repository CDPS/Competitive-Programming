#include <bits/stdc++.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n, k, l1, l2, acc;
	char c;
	double h, ans;
	cin >> t;
	while(t--) {        
		cin >> n;
		h = 0.0; l1 = 0; l2 = 0; acc = 0;
		while(n--) {
			cin >> c >> k;
			if(acc == 0){
				l1+=k; l2+=k;
			}
			if(acc == 1) l1+=k;
			if(acc == 4) l2+=k;
			if(c == 'C') {
				acc++;
				if(acc == 4) l2+=k;
				h += k*k;	
			} else if(c == 'S')
				h += k*k;
			else
				h += (k*k)*(sqrt(3)/4);
		}
		ans = (l1*l2) - h;
		cout << fixed << setprecision(4) << ans << endl;					 
	}
   	
	return 0;
}
