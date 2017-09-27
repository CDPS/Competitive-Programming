#include <bits/stdc++.h>

using namespace std;

int a[100];
int b[100];

int main(){

    int n,m;

    while(scanf("%d",&n) && n!=0){
        scanf("%d",&m);

        for(int i=0;i<n;i++)
        scanf("%d",a+i);

        for(int i=0;i<m;i++)
            scanf("%d",b+i);

        vector<double> ratios;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ratios.push_back(double(b[j])/double(a[i]));
            }
        }

        sort(ratios.begin(),ratios.end());
        double maxi=-1;

        for(int i=1;i<ratios.size();i++){
            maxi= max(ratios[i]/ratios[i-1], maxi);
        }

        printf("%.2lf\n",maxi);
    }

    return 0;
}
