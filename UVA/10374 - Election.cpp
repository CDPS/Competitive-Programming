#include <bits/stdc++.h>

using namespace std;

char a[84], b[84];

int main(){

    int t,n;
    scanf("%d", &t);
    string s;

    while(t--){

        scanf("%d\n", &n);
        map<string, string> mp;
        while(n--){
           gets(a);
           gets(b);
           mp[string(a)]=string(b);
        }

        scanf("%d\n", &n);
        map<string, int> votes;
        int maxi =0;
        int acc = 0;
        string ans = "tie";

        while(n--){
             gets(a);
             s = string(a);

             if(!mp.count(s)) continue;
             votes[s]++;
             if(votes[s]> maxi){
                acc =1;
                ans = mp[s];
                maxi = votes[s];
             }
             else if(votes[s] == maxi){
                acc++;
             }
        }

        if(acc == 1 )
            printf("%s\n", ans.data());
        else
            printf("tie\n");

        if(t)
            printf("\n");
    }

    return 0;
}
