#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;

    map<char, int> mp;
    mp['B'] = 0;
    mp['u'] = 1;
    mp['l'] = 2;
    mp['b'] = 3;
    mp['a'] = 4;
    mp['s'] = 5;
    mp['r'] = 6;

    cin >> s;

    vector <int> v(7,0);

    for(int i=0;i<s.size();i++ ){
        if(s[i] == 'B'|| s[i] == 'a' ||s[i] == 'u' ||s[i] == 'l' ||s[i] == 'b' || s[i] == 's' ||s[i] == 'r'){
                v [ mp[ s[i] ] ]++;
        }
    }

    int mina = min(v[0] , min( v[2], min(v[6],  min(  v[3],v[5] ) )));
    int minb = min( v[1],v[4] );
    int res=0;

    int i=0,j=0;

    while( i<mina && j< minb){
            i++;
            j+=2;
            res++;
            if(i>mina || j> minb)
                res--;
    }

    printf("%d\n",res);
    return 0;
}
