#include <bits/stdc++.h>

using namespace std;


int main(){

    map <string,int> mapPer;
    map <string,int>::iterator it;
    string s;
    int kase, sum;

    cin >> kase;
    cin.ignore(2);
    while (kase--) {
        sum = 0;
        while (getline(cin,s) && s.length()) {
            mapPer[s]++;
            sum++;
        }
        for (it = mapPer.begin(); it!=mapPer.end(); it++) {
            cout << it->first << " ";
            printf("%.4lf\n",(it->second)*100.0/(double)sum);
        }
        if (kase) cout << endl;
        mapPer.clear();
    }

	return 0;
}
