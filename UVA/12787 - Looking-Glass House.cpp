#include <bits/stdc++.h>

using namespace std;

bool isPal(int n, int base) {
	vector<int> a;
	while(n)
        a.push_back(n%base), n /= base;

	for (int i=0,j=a.size()-1; i < j; i++, j--)
		if (a[i] != a[j])
			return false;
	return true;
}

int main(){

    int n;
    while(cin >> n){
        if (n <= 2) { cout << n+1 << "\n"; continue; }
        int ans = INT_MAX;
        for(int i=2;i*i<n ;i++){
            if(isPal(n,i)){ ans = i; break; }
            if(isPal(n,n/i-1)) ans = min(ans,n/i-1 );
        }
        cout << ( (ans != INT_MAX )? ans: n-1 ) << "\n";
    }

    return 0;
}
