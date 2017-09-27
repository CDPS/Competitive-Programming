#include <bits/stdc++.h>

using namespace std;

int n,c,a[20];

string toString(int n){
    stringstream ss; string s;
    ss << n; ss >>s;
    return s;
}

int maxi; string res;

void backtrack(int idx,int acc,string s){

    if(idx==c && acc <=n ){
        if(acc>maxi) maxi = acc, res = s;
        return;
    }
    if(acc>n) return;

    backtrack(idx+1,acc,s); backtrack(idx+1,acc+a[idx], s+ " " +toString(a[idx]));
}

int main(){

    while(scanf("%d",&n)==1){

          scanf("%d",&c);
          for(int i=0;i<c;i++)
              scanf("%d",a+i);

           maxi=0; backtrack(0,0,"");
           cout <<  res.substr(1,res.size()) << " sum:" <<  maxi<<"\n";
    }
    return 0;
}
