#include <bits/stdc++.h>

using namespace std;

int main() {
	
	string s, k, m;
	char c;
	cin >> s >> k;
	m = "";
	for(int i = 0; i < s.size(); i++) {		
		c = ((s[i]-'A')-(k[i]-'A')+26)%26;
		c += 'A';
		m += c;
		k += c; 	
	}
	cout << m << endl;	
   	
	return 0;
}