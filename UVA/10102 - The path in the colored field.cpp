#include<bits/stdc++.h>

using namespace std;

int main(){

    int n; char c;

    while(scanf("%d",&n)==1){

        vector<pair<int,int> > ones,threes;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf(" %c",&c);
                if(c=='1') ones.push_back(make_pair(i,j));
                if(c=='3') threes.push_back(make_pair(i,j));
            }
        }

        int maxi=-1,mini;

        for(int i=0;i<ones.size();i++){
            mini = 1000000;
            for(int j=0;j<threes.size();j++)
                mini = min(mini,( abs(ones[i].first-threes[j].first) + abs(ones[i].second-threes[j].second) ) );
            maxi = max(maxi,mini);
        }
        printf("%d\n",maxi);
    }
    return 0;
}
