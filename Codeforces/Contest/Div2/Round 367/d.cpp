#include <bits/stdc++.h>

using namespace std;


long y;

int getMid(int s, int e) {
    return  (e +s)/2;
}

int constructSTUtil(vector<long> arr, int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss] ^ y;
        return st[si];
    }

    int mid = getMid(ss, se);
    st[si] =  max(constructSTUtil(arr, ss, mid, st, si*2+1),
              constructSTUtil(arr, mid+1, se, st, si*2+2) );
    return st[si];
}

int *constructST(vector<long> arr, int n)
{
    int x = (int)(ceil(log2(n)));

    int max_size = 2*(int)pow(2, x) - 1;

    int *st = new int[max_size];

    constructSTUtil(arr, 0, n-1, st, 0);

    return st;
}


int main(){
    long q;
    scanf("%ld",&q);

    multiset<long> s;
    s.insert(0);

    while(q--){

        char op; long x;

        cin >> op >> x;


        if(op=='+'){
            s.insert(x);
        }

        if(op=='-'){
            s.erase(x);
        }

        if(op=='?'){
            y=x;
            multiset<long>::iterator it;
            vector<long> v;
            for (it=s.begin(); it!=s.end(); ++it){
                v.push_back(*it);
            }
            int *st = constructST(v,v.size());
            printf("%ld\n",st[0]);
        }
    }
    return 0;
}
