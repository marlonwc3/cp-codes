#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

typedef pair<int, int> ii; //x,y s
typedef pair<bool, ii> bii;
int r=4, c=4, numPistas;

int m[105][105];
int dist[105][105];
int des[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1}};
queue<ii> q;
bool mark[105][105];



int put(int x, int y, int k ){
    
    dist[x][y] = 0; ii no;
    int dx, dy;
    q.push(make_pair(x,y));
    while(!q.empty()){
        no = q.front(); q.pop();
        x = no.first; y = no.second;
        if(dist[x][y] > k ) continue;
        m[x][y] += dist[x][y]==k;
        //printf("x:%d y:%d -> d:%d\n",x ,y , dist[x][y]);
        for(int i=0;i<4; i++){
            dx = x + des[i][0];
            dy = y + des[i][1];
            if(dx < 0 || dx >= r || dy < 0 || dy >= c) continue;
            if(!mark[dx][dy]){
                //printf("entrou\n");
                mark[dx][dy] = 1;
                dist[dx][dy] = 1 + dist[x][y];
                q.push(make_pair(dx,dy));
            }
        }
    }
}


ii verif(){
    int x,y, cont=0;
    for(int i=0; i < r; i++){
        for(int j=0; j < c; j++){
            if(m[i][j] == numPistas)  {
                cont++;
                x=i; y=j;
            }
            if(cont >= 2 ) return make_pair(-1,-1);
        }
    }
    return make_pair(x,y);
}


int main (int argc, char const* argv[]) {
    
    int x=0, y, k, w;
    ii res;
    int n;
    while(scanf("%d %d", &n, &numPistas) > 0){
        r=c=n;
        memset(m, 0, sizeof m);
        for(int i=0; i < numPistas; i++){
            memset(dist, 0, sizeof dist);
            memset(mark, 0, sizeof mark);
            scanf("%d %d %d", &x, &y, &k);
            w = x;
            x = (r-1)-y;
            y = w;
            put(x, y, k);
        }
        res = verif();
        w = res.second;
        if(w>=0) y = r-1 - res.first;
        else y=-1;
        x = w;
        printf("%d %d\n", x,y);
    }


    

    
    
    
    return 0;
}

