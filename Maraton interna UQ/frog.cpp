#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int dis[50];

int main() {

    int t, c, d, res,caseno=1;
    string s;
    scanf("%d", &t);

    while(t--) {

        scanf("%d %d", &c, &d);


        for(int i=0;i<50;i++)
            dis[i]=100;

        cin >> s;
        dis[0]=0;

        printf("Day #%d\n",caseno++);
        printf("%d %d\n", c,d);
        cout<< s << endl;

        if(d>=c)
            if(s[c-1]!='X')
                printf("1\n");
            else
                printf("0\n");
        else{
            for(int i=0;i< c-d +1;i++){
                for(int j=1; j<=d+1 && j<c ;j++){
                    if(s[i+j]!='X'){
                        dis[i+j]= min(dis[i]+1,dis[j+i]);
                    }
                }
            }
            if(dis[c-1]==100)
                printf("0\n");
            else
                printf("%d\n",dis[c-1]);
        }
        printf("\n");
    }

    return 0;
}

