#include <stdio.h>
#include <queue>
using namespace std;

class Compare {
public:
    bool operator()(int& a, int& b)
    {
       if (a >= b) return true;
        return false;
    }
};

int main(){

    priority_queue<int, vector<int>, Compare> pq;
    int t,caseno=1;

    scanf("%d",&t);
    while(t--){
        priority_queue<int> x1s;
        priority_queue<int> y1s;
        priority_queue<int> z1s;
        priority_queue<int, vector<int>, Compare> x2s;
        priority_queue<int, vector<int>, Compare> y2s;
        priority_queue<int, vector<int>, Compare> z2s;
        int n;
        scanf("%d",&n);
        while(n--){
            int x1,x2,y1,y2,z1,z2;
            scanf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
            x1s.push(x1);
            y1s.push(y1);
            z1s.push(z1);
            x2s.push(x2);
            y2s.push(y2);
            z2s.push(z2);
        }

        long lx = x2s.top() - x1s.top();
        long ly = y2s.top() - y1s.top();
        long lz = z2s.top() - z1s.top();
        long res = lx*ly*lz;
        if(res>0){
            printf("Case %d: %ld\n",caseno++,res);
        }else{
            printf("Case %d: 0\n",caseno++);
        }
    }
    return 0;
}
