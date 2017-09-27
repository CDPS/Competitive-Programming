#include <bits/stdc++.h>

using namespace std;


struct myclass {
  bool operator() (int i,int j) { return (i>j);}
} myobject;

int main(){

    int n;
    scanf("%d",&n);

    vector<int> e,o;
    int j;
    for(int i=0;i<n;i++){
        scanf("%d",&j);
        if(j%2)
            o.push_back(j);
        else
            e.push_back(j);
    }

    sort(e.begin(),e.end());
    sort(o.begin(),o.end(),myobject);

    for(int i=0;i<e.size();i++){
        printf("%d\n",e[i]);
    }

    for(int i=0;i<o.size();i++){
        printf("%d\n",o[i]);
    }
    return 0;
}
