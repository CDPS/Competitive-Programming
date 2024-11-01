#include <bits/stdc++.h>

using namespace std;

int a[31];

bool split(char c ){
    return c == ' ' || c == '?' || c == '!' || c == ',' || c == '.';
}

int main(){

    string s;

    int acc = 0;
    while(getline(cin, s)){

        if(s[0]!= '#'){

            for(int i=0;i<s.size();i++){
                if(isalpha(s[i])) acc++;
                if(split(s[i])) a[acc]++, acc =0;
            }
            if(s[s.size()-1]!= '-') a[acc]++, acc =0;

            continue;
        }

        for(int i=1;i<30;i++)
            if(a[i]>0)
                cout << i << " " << a[i] << "\n";
        cout << "\n";
        memset(a, 0, sizeof a);
        acc = 0;
    }
    return 0;
}
