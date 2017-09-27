//============================================================
// Name        : Guilty Prince.cpp
// Author      : Team UQuick
// Author      : Fabio Stiven Oquendo Soler
// Author      : Cristian Daniel Palechor Sepulveda
// Description : Programming Problems Light OJ
// Number      : 1012
//============================================================


#include <bits/stdc++.h>

using namespace std;

char matriz [20][20];
int w, h;


bool valido (int x, int y) {

    if (x>=0 && x<h && y>=0 && y<w) {

        if (matriz[x][y] == '.') {

            return true;
        }
    }

    return false;

}

int bfs (int x, int y) {

    queue< pair<int,int> > cola;

    cola.push(pair<int,int>(x,y));

    int res = 1;

    while (!cola.empty()) {

        pair<int,int> par = cola.front();
        int x1 = par.first;
        int y1 = par.second;
        cola.pop();

        if (valido(x1-1, y1)) {

            matriz[x1-1][y1] = '@';
            cola.push(pair<int,int>(x1-1,y1));
            res++;
        }

        if (valido(x1+1, y1)) {

            matriz[x1+1][y1] = '@';
            cola.push(pair<int,int>(x1+1,y1));
            res++;
        }

        if (valido(x1, y1-1)) {

            matriz[x1][y1-1] = '@';
            cola.push(pair<int,int>(x1,y1-1));
            res++;
        }

        if (valido(x1, y1+1)) {

            matriz[x1][y1+1] = '@';
            cola.push(pair<int,int>(x1,y1+1));
            res++;
        }
    }

    return res;
}

int main() {

    int t, cases=1, w1, h1, res;

    scanf("%d", &t);

    while (t--) {

        scanf("%d %d", &w, &h);

        for (int i=0; i<h; i++) {

            for (int j=0; j<w; j++) {

                scanf(" %c", &matriz[i][j]);

                if (matriz[i][j] == '@') {

                    h1= i;
                    w1= j;
                }
            }
        }

        res = bfs(h1, w1);

        printf("Case %d: %d\n", cases++, res);
    }

    return 0;
}
