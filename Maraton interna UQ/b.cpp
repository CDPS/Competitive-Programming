#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {

    int l, r, d, res;
    string s;
    bool rest, drog;

    while(scanf("%d", &l) == 1) {

        cin >> s;
        res = 2000010;
        rest = false; drog = false;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == 'Z') {

                res = 0;
                break;
            }

            if(s[i] == 'R') {

                r = i;
                if(drog == true) {

                    res = min(res, r-d);
                }
                rest=true;
                drog=false;
            }

            if(s[i] == 'D') {

                d = i;
                if(rest == true) {

                    res = min(res, d-r);
                }
                drog = true;
                rest=false;
            }
        }

        printf("%d\n", res);
    }

    return 0;
}
