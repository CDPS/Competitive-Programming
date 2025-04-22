#include <bits/stdc++.h>

using namespace std;

struct height{
    int h, w, idx;
    height(int h, int w, int idx) : h(h), w(w), idx(idx){}
    bool operator < (const height &a) const {
        return h < a.h;
    }
};

struct width{
    int h, w, idx;
    width(int h, int w, int idx) : h(h), w(w), idx(idx){}
    bool operator < (const width &a) const {
        return w < a.w;
    }
};

pair<int,int> hsfx[200000];
pair<int,int> wsfx[200000];

int ans[200000];

int main(){

    cin.sync_with_stdio(false); cin.tie(NULL);

    int t, n, h , w;

    cin >> t;

    while(t--){

        cin >> n;

        vector<height> hs;
        vector<width>  ws;
        for(int i=0;i<n;i++){
            cin >> h >> w;
            hs.push_back(height(h,w,i));
            ws.push_back( width(h,w,i));
        }

        sort(hs.begin(), hs.end());
        sort(ws.begin(), ws.end());

        hsfx[0] = {hs[0].w,hs[0].idx};
        wsfx[0] = {ws[0].h,ws[0].idx};
        for(int i=1;i<n;i++){
            hsfx[i] =  ( hs[i].w < hsfx[i-1].first )? make_pair(hs[i].w, hs[i].idx) : hsfx[i-1];
            wsfx[i] =  ( ws[i].h < wsfx[i-1].first )? make_pair(ws[i].h, ws[i].idx) : wsfx[i-1];
        }


        for(int i=0;i<n;i++){

            auto hit = lower_bound(hs.begin(),hs.end(),height( hs[i].h,0,0));
            if (hit != hs.begin()) {
                --hit;
                if( hsfx[hit - hs.begin()].first < hs[i].w ){
                    ans[hs[i].idx] = hsfx[hit - hs.begin()].second + 1;
                    continue;
                }
            }

            auto wit = lower_bound(ws.begin(),ws.end(),width( 0,hs[i].h,0));

            if (wit != ws.begin()) {
                --wit;
                if( wsfx[wit - ws.begin()].first < hs[i].w ){

                    ans[hs[i].idx] = wsfx[wit - ws.begin()].second + 1;
                    continue;
                }
            }

            ans[hs[i].idx] = -1;
        }

        for(int i=0;i<n;i++)
            cout << ans[i] << " \n"[i==n-1];
    }

    return 0;
}
