#include <bits/stdc++.h>

using namespace std;

long long dp[510][3][(500*9) +10];

bool m[ (500*9) + 10];

int k=1000000007;
void criba(int  tam){
    m[0] = false;
    m[1] = false;
    for(int i = 2; i <= tam; ++i)
        m[i] = true;

    for(int i = 2; i*i <= tam; ++i) {
        if(m[i]) {
            for(int h = 2; i*h <= tam; ++h)
                m[i*h] = false;
        }
    }
}


long long f(string n,int idx,int top,int acc){

	if(idx==n.size()){

		return m[acc];
	}

	if(dp[idx][top][acc]!=-1)
		return dp[idx][top][acc]%k;

	int max= (top? (n[idx]-'0'):9);

	long long res=0;

	for(int i=0;i<=max;i++){
		res+= f(n,idx+1,top&&(i==max), acc+i)%k;
	}

	return dp[idx][top][acc]=res;
}

int main(){


    string a,b;

    criba(4505);

	while(cin >> a >> b ){

		memset(dp,-1,sizeof dp);
		long long res2 = f(b,0,1,0)%k;

		memset(dp,-1,sizeof dp);

		int sum=0;
		for(int i=0;i<a.size();i++){
            sum+= a[i]-'0';
		}

		long long res1 = f(a,0,1,0)%k;

		long long res= (res2-res1+k)%k + m[sum];

		printf("%lld\n",res);
	}

    return 0;
}
