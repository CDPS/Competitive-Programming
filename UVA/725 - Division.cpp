#include <bits/stdc++.h>

using namespace std;


string toString(int n, int f){
    string s="";
    while(n){
        int d = n%10;
        s= char(d+'0') + s;
        n/=10;
    }
    if(f) s= '0' +s;
    return s;
}

bool isValid(string s){

    vector<int> frec(10,0);

    for(int i=0;i<s.size();i++){
        frec[ s[i]-'0' ]++;
        if(frec[s[i]-'0']==2)
            return false;
    }
    return true;
}

int main(){

    int n;

    bool first = true;
    bool sol;

    while( cin >> n && n!=0){

        sol = false;
        if(!first) cout << "\n";
        first = false;

        for(int i=1234; i<= 98765 && i*n < 98765 ; i++){

            int r = n *i;

            string a = toString(r, r< 10000? 1:0);
            string b = toString(i, i< 10000? 1:0);

            if(isValid(a+b) && a.size()==5 && b.size()==5){
                sol = true;
                cout << a << " / " << b << " = " << n << "\n";
            }
        }

        if(!sol) cout << "There are no solutions for " << n << ".\n";
    }
    return 0;
}
