#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;

    cin >> s;

    vector<int> v(4,-1);
    vector< int> acc(4,0);

    for(int i=0;i<s.length();i++){
        if(s[i]=='R'){
            v[i%4] = 0 ;
        }
        if(s[i]=='B'){
            v[i%4] = 1;
        }
        if(s[i]=='Y'){
            v[i%4] = 2;
        }
        if(s[i]=='G'){
            v[i%4]=3;
        }
    }

    for(int i=0;i<s.length();i++){
        if(s[i]=='!'){
            acc[  v[i%4]  ]++;
        }
    }
    printf("%d %d %d %d\n",acc[0],acc[1] ,acc[2], acc[3]);
    return 0;
}
