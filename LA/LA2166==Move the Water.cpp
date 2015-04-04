#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-9
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;

int cap[6];

struct state {
    int c[4];
    state(){}
    bool operator == (const state &s) const{
        return c[0] == s.c[0] && c[1] == s.c[1] && c[2] == s.c[2];
        //return 1;
    }

};

vector<state> get(state s){
    vector<state> res;
    int da, db, dc;
    int c[4];
    fr(i,0,3){
        //printf("oi 13\n");
        fr(j,0,3){
            if(i==j ) continue;
          //  printf("oi 2\n");
            memcpy(c, s.c, sizeof s.c);
           // printf("oi 1\n");
            int d = cap[j] - c[j];
            d = min( c[i], d  );
            if(!d) continue;
//            printf("ci: %d | de %d--> %d | d: %d \n",c[i],i,j,d );
            c[j]+=d;
            c[i]-=d;
            state s2 = state();
         //   printf("oi 5\n");
            memcpy(s2.c, c, sizeof c);
          //  printf("oi 6\n");
            res.pb(s2);
            if(0) fr(w,0,3){
                printf("%d ",  s2.c[w]);
            }
           // printf("oi 7\n");
          //  _            
        }
    }
    //printf("oi 15\n");
    return res;
}

int d[152][152][152];
state lol;
int go(state s){
    queue<state> q;
    int a, b, c, dis;
    a = s.c[0], b = s.c[1], c = s.c[2];
    vector<state> adjList;
    d[a][b][c] = 1;
    q.push(s);
    state adj;

    fr(i,0,3){
        //printf("%d ", lol.c[i] );
    }
   // _

    while(!q.empty()){
        s = q.front(); q.pop();
        a = s.c[0], b = s.c[1], c = s.c[2];

        dis = d[a][b][c];
       // printf("state: %d %d %d | %d \n", a, b ,c, dis);        
        if( s == lol) return dis;
      //  printf("oi 12\n");
        adjList = get(s);
      //  printf("oi 10\n");
        fr(i,0,adjList.size()){
            a = adjList[i].c[0];
            b = adjList[i].c[1];
            c = adjList[i].c[2];
         //   printf("oi 11\n");
            if(d[a][b][c]) continue;
            d[a][b][c] = dis+1;
            adj = state();
          //  printf("oi 3\n");
            memcpy(adj.c, adjList[i].c, sizeof adjList[i].c);
          //  printf("oi 4\n");
            q.push(adj);
           // printf("oi 9\n" );
        }
    }


    return -1;
}




int main(int argc, char const *argv[]) {
    state s;
    int res;

    while(1){
        sc1(cap[0]);
        if(!cap[0]) break;
        s = state();
        lol = state();
        fr(i,1,3) sc1(cap[i]);
        fr(i,0,3) { sc1(s.c[i]); }
        fr(i,0,3) { sc1(lol.c[i]); }
        mst(d, 0);
        res = go(s);
        if(res>0) res--;
        printf("%d\n", res   );

    }



    return 0;
}
