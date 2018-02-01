#include <bits/stdc++.h>

using namespace std;

double oo = 10000000000000;

struct point{
    int x,y;
    point(int a,int b){x=a;y=b;}
};

int n; vector<point> v;
double  memo[ (1 << 16) +1], d[16][16];

int bits(int i){
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

double dp(){

    memo[0] = 0.0;
    for(int mask=0 ; mask< (1 << n );mask++)
        if(bits(mask)%2==0)
            for(int i=0;i<n;i++)
                if( ( mask&(1<<i) ) != 0 )
                    for(int j = i +1; j< n;j++)
                        if( ( mask & ( 1 << j ) ) != 0 )
                            memo[mask] = min( memo[mask] , d[i][j] + memo[mask ^ (0 | (1 << i) | (1 << j)) ] );
    return memo[(1 << n) -1];
}

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    string s ; int x, y, caseno = 1;

    while(cin >> n && n){

        n = 2 * n;
        for(int i=0;i<n;i++)
            cin >> s >> x >> y, v.push_back(point(x,y));

        for(int i=0; i < (1 << n); i++) memo[i] = oo;

        for(int i=0;i<n;i++)
            for(int j=0; j< n;j++)
                d[i][j] = sqrt( (v[i].x-v[j].x)*(v[i].x-v[j].x) + (v[i].y-v[j].y)*(v[i].y-v[j].y) );

        cout << "Case " << caseno++ << ": " << fixed << setprecision(2) << dp() << "\n";
        v.clear();
    }
    return 0;
}
