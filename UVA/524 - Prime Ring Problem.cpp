#include <bits/stdc++.h>

using namespace std;

int m[40];

string toString(int n){
	stringstream ss;
	ss << n;
	return  ss.str();
}
void sieve(int n){
    m[0]=m[1]=0;
    for(int i=2;i<=n;i++)
        m[i]=1;
    for(int i=2;i*i<=n;i++){
        if(m[i]){
            for(int j=i+i;j<=n;j+=i){
                m[j]=0;
            }
        }
    }
}
void backtrack(int number,int limit, vector<int> &used,string res,int counter){
	if(counter > limit)
        return;
    if(counter == limit && m[number+1]){
    	cout << res<< "\n";
        return;
    }
    for(int i=1;i<=limit;i++){
        int v = number+i;
        if(  m[v]  && !used[i]){
            used[i]=1;
            string r1 = res;
            backtrack(i,limit,used,r1+= " "+toString(i),counter+1);
            used[i]=0;
        }
    }
}

int main(){
    sieve(37);
    int n,caseno=1;
    while(scanf("%d",&n)==1){
    	if(caseno>1)printf("\n");
        vector<int> used(n+1,0);
        used[1]=1;
        printf("Case %d:\n",caseno++);
        backtrack(1,n,used,"1",1);
    }
    return 0;
}
