#include <bits/stdc++.h>

using namespace std;

long a[40000];

int main(){

    int n, caseno = 1;

    while(cin >> n && n ){

        for(int i=0;i<n;i++)
            cin >> a[i];

        sort(a, a+n);

        int ans = 0;

		for(int i =1,j=0;i<n;i++) {
			while(a[j] < a[i]) j++;
			ans += j;
		}

        cout << "Case " << caseno++ << ": " << ans << "\n";
    }

    return 0;
}
