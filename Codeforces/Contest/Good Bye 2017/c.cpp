#include <bits/stdc++.h>

using namespace std;

int a[1000];
int n,r;

bool overlap(int x,int y){
    if((y-x)<=2*r)
        return true;
    return false;
}

int main(){

    scanf("%d %d",&n,&r);
    for(int i=0;i<n;i++) scanf("%d",a + i);

    vector<double> ans;
    for(int i=0;i<n;i++){
        double y = r;
        for(int j=0; j<i;j++){
            if(overlap(min(a[j],a[i]),max(a[j],a[i]))){
                    int d = 2.0*r;
                    int xo = a[i]-a[j];
                    y = max(y, ans[j] + sqrt( (d*d) - (xo*xo)) ) ;
            }
        }
        ans.push_back(y);
    }

    for(int i =0;i<n;i++)
        printf("%.12lf%s",ans[i],(i==n-1)?"\n":" ");
    return 0;
}
