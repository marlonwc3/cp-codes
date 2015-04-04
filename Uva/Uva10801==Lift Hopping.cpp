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

int arr[6], dist[105][6], n, k;
bool chega[105][6];
vi lol[6];

struct Node {
    int no, d, el;
    Node(){}
    Node(int _no, int _d, int _el){ no = _no, d = _d; el = _el;} 
    bool operator < (const Node &node) const{ return d > node.d; }
};

int dijkstra(){
    mst(dist, inf);
    priority_queue<Node> pq;
    mst(dist[0], 0);
    int no, b, d, vel, s, t, el;
    Node node;
    fr(i,0,n){ pq.push(Node(0,0,i)); }
    while(!pq.empty()){
        node = pq.top(); pq.pop();
        no = node.no, d = node.d, el = node.el;
        if(no == k ){ return d; break;} 
        if(dist[no][el]!=d) continue;
        fr(i,0,n){
            if(!chega[no][i]) continue;
            vel = arr[i];
            s = lol[i].size();
            fr(j,0,s){
                b = lol[i][j];
                if(b==no) continue;
                t = d+ abs( no - b )*vel;
                if( i != el ) { t+=60; }
                if(dist[b][i] > t ){
                    dist[b][i] =t;
                    pq.push(Node(b, t ,i));
                }
            }
        }
    }
    return inf;
}

char line[10000];
int main(int argc, char const *argv[]) {
    int a ,b;
    while( sc2(n, k) == 2 ){
        fr(i,0,n) sc1(arr[i]);
        mst(chega, 0 );
        fr(i,0,6) lol[i].clear();
        gets(line);
        fr(i,0,n){
            gets(line);
            char *pch = strtok(line, " ");
            while( pch != NULL ){
                sscanf( pch, "%d", &a );
                chega[a][i] = 1;
                lol[i].pb(a);   
                pch = strtok(NULL, " ");
            }
        }
        a = dijkstra();
        if( a < 0 || a >= inf ) printf("IMPOSSIBLE\n");
        else printf("%d\n", a);
    }
    return 0;
}