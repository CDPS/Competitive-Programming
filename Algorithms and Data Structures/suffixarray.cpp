#include <bits/stdc++.h>

using namespace std;

string s; int n;

int RA[100010],tempRA[100010];
int SA[100010],tempSA[100010];

void buildSuffixArray(){

    for(int i=0;i<n;i++) RA[i]=s[i], SA[i]=i;

    int r;
    for(int k=1;k<n;k= (k<<i)){
        //sort
        tempRA[SA[0]]=r=0;
        for(int i=1;i<n;i++){
            tempRA[SA[i]]= (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        }

        for(int i=0;i<n;i++) RA[i]=tempRA[i];

        if (RA[SA[n-1]] == n-1) break;
    }
}
int main(){

    return 0;
}
