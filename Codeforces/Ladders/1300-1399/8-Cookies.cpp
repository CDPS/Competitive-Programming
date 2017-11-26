#include <bits/stdc++.h>

using namespace std;

int a[100];

int main(){
	int n,sum=0;

	scanf("%d",&n);
	for(int i=0;i<n;i++)
	   scanf("%d",a+i),sum+=a[i];
	int ans=0;
	for(int i=0;i<n;i++){
            int x = sum-a[i];
	    if(x%2==0) ans++;
	}
	printf("%d",ans);
	return 0;
}
