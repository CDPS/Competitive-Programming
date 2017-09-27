#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main() {

    int t, c, v;
    string s;
    scanf("%d", &t);
    while(t--) {

        cin >> s;
        c = 0; v = 0;
        for(int i = 0; i < s.size(); i++) {

            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {

                v++;
            } else {
                c++;
            }
        }

        cout << s << endl;

        if(v>c) {

            printf("1\n");
        } else {
            printf("0\n");
        }

    }

    return 0;
}
