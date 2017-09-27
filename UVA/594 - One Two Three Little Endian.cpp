#include <bits/stdc++.h>

using namespace std;

int getOpsiteEndianP(string n){
    long res=0;
    for(int i=1;i<n.size();i++){
        if(n[i]=='1'){
            res+= (1<<(31-i) );
        }
    }
    return res;
}

long getOpsiteEndianN(string n){
    long res=0;
    for(int i=1;i<n.size();i++){
        if(n[i]=='0'){
            res+= (1<<(31-i));
        }
    }
    return res;
}

string getEndian(long n){
    bitset<32> b(n);
    string a="", r="";
    int j=1;
    for(int i=b.size()-1;i>=0;i--){
        a= (b[i])?  a  + "1" : a + "0";
        if(j%8==0){ r =a + r ; a=""; }
        j++;
    }
    return r;
}

int main(){
    long n;
    while(scanf("%ld",&n)==1){
        string sn = getEndian(n);
        long res = (sn[0]=='1')?  ( getOpsiteEndianN(sn) +1)*(-1): getOpsiteEndianP(sn);
        printf("%ld converts to %ld\n",n,res);
    }
    return 0;
}
