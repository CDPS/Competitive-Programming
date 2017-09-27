#include <bits/stdc++.h>

using namespace std;

const string ln = "\n";

vector<int> compute_Z(string s) {

    int n = s.size();
    vector<int> z(n,0);
    int l, r, k;
    r = l = 0;

    for(int i = 1; i < n; i++) {

        if(i > r) {

            l = r = i;
            while(r < n && s[r-l] == s[r]) r++;
            z[i] = r-l; r--;

        } else {

            k = i - l;
            if(z[k] < r-i+1) z[i] = z[k];
            else {

                l = i;
                while(r < n && s[r-l] == s[r]) r++;
                z[i] = r-l; r--;
            }
        }
    }
    return z;
}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
	int ms, ans; 
	string s, aux, ss;
	vector<int> z;
	cin >> s;
	ans = s.size();
	for(int i = 0; i < s.size(); i++) {
		for(int j = 1; j <= s.size()-i; j++) {
			aux = s.substr(i,j);
			z = compute_Z(aux+"$"+s);
			ms = 0;
			for(int i = aux.size()+1; i < z.size();) {
				if(z[i] == aux.size()) {           
					ms++;
					i+=aux.size();
				} else i++;
			}
			if(ans > ((int)s.size()-((int)aux.size()*ms))+ms+(int)aux.size()) {
            	ans = ((int)s.size()-((int)aux.size()*ms))+ms+(int)aux.size();
				ss = aux;
			}
		}
	}
	cout << ans << ln;

	return 0;
}