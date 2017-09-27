#include <bits/stdc++.h>


using namespace std;

int a[100];

int main(){
  int n,k;
  cin >> k >> n;

  for(int i=0;i<n;i++)
    a[i]=0;

  int idx; string o;

  a[0]=1;
  a[n-1]=2;

  while(k--){
    cin >> idx >> o;
    if(o[0]=='B'){
      a[idx-1]=2;
    }else{
      a[idx-1]=1;
    }
  }

  int r2;
  for(int i=n-1;i>=0;i--){
    if(a[i]==2)r2=i;
  }

  int r1;

  for(int i=0;i< n;i++){
    if(a[i]==1)r1=i;
  }

  cout << r1+2 << " " << r2 << "\n";
  return 0;
}
