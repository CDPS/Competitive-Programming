#include <bits/stdc++.h>
 
using namespace std;
 
 int n,q,BLOCK_SIZE;
 
 
inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}
 
 
struct Mo
{
 
    int MAX_VALUE = 100001;
 
    vector<long long> cnt;
 
    long long current_answer;
 
    public:
 
    Mo(){
        cnt = vector<long long>(MAX_VALUE, 0);
        current_answer = 0;
    }
 
    long long get_answer() const {
 
        return current_answer;
    }
 
    void add(int number){
 
        cnt[number]+=1;
 
        if(cnt[number]==1)
            current_answer++;
    }
 
    void remove(int number){
 
        cnt[number]-=1;
 
        if(cnt[number]==0)
            current_answer--;
    }
};
 
 
int main(){
 
 
    int t,caseno=1;
    scanf("%d",&t);
 
    while(t--){
 
 
        scanf("%d %d",&n,&q);
 
        BLOCK_SIZE= (int)(sqrt(n));
 
        vector<int> a(n);
        vector<long long> answers(q);
 
        vector < pair< pair<int, int>, int> > queries;
        queries.reserve(q);
 
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
 
        for(int i=0;i<q;i++){
            int l,r;
            scanf("%d %d",&l,&r);
            queries.push_back(make_pair(make_pair(l-1,r-1),i));
        }
 
        sort(queries.begin(), queries.end(), mo_cmp);
 
        Mo mo;
 
        int ml=0, mr=-1;
 
        for(int i=0;i< q;i++){
 
            int l = queries[i].first.first;
            int r = queries[i].first.second;
 
            while(mr < r) {
                mr++;
                mo.add(a[mr]);
            }
 
            while(mr > r) {
                mo.remove(a[mr]);
                mr--;
            }
 
            while(ml < l)  {
                mo.remove(a[ml]);
                ml++;
            }
 
            while(ml > l) {
                ml--;
                mo.add(a[ml]);
            }
 
            answers[queries[i].second] = mo.current_answer;
        }
 
        printf("Case %d:\n",caseno++);
        for(int i=0;i<q;i++)
            printf("%lld\n",answers[i]);
 
    }
    return 0;
}
