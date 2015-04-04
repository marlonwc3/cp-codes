#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<char, int> ci;

#define addEdge(a,b) to[z] = b; ant[z] = adj[a]; adj[a] = z++
#define addEdgeC(a,b,c) from[z] = a; to[z] = b; ant[z] = adj[a]; adj[a] = z; cost[z] = c; z++
#define rp(a,b) fr(a,0,b)
#define MP make_pair
#define F first
#define S second
const int infinity = 0x3f3f3f3f;
const long long longInfinity = 0x3f3f3f3f3f3f3f3fLL;
typedef pair<int,int> pii;
typedef pair<pii,int> trii;
typedef long long ll;
typedef priority_queue<pii, vector<pii>, greater<pii> > HeapPii;

typedef long long ll;
typedef pair<int, int> ii;





int getPos(string s){
        if( s=="goalkeeper") return 0;
        if(s=="defender") return 1;
        if(s == "midfielder") return 2;
        if (s=="striker") return 3;
}

/*
G =0
Z = 1
mmid  = 2
striker = 3

*/
struct tripla{
    int jogador, pos, val;
    tripla(){}
    tripla(int _jogador, int _pos, int _val){
        jogador=_jogador, pos=_pos, val=_val;
    }
    
    bool operator < (const tripla &t) const{
        if(pos == t.pos) return jogador < t.jogador;
        return pos < t.pos;
    }
};

map<string, int> mymap;
int NEXT;
int get(string s){
    int r = mymap[s];
    if(!r) return mymap[s] = NEXT++;
    return r;
}
vector<tripla> jogadores;

char str1[300], str2[300];

int matrix[100][100];
int matrix_custo[100];


vi myteam;
vi v2;
int res = -1;
int custo(){
    int sum = 0;
    fr(i,0,myteam.size()){
        //printf("Jogador: %d custo: %d \n", myteam[i], matrix_custo[myteam[i] ]);
        sum += matrix_custo[myteam[i]];
        fr(j,i+1, myteam.size()){
           if(i==j) continue;
           sum += matrix[myteam[i]][myteam[j]];
        }    
    }
    if(sum > res ) {v2 = myteam, res=sum;} 
   // printf("sum: %d \n", sum);
    return sum;
}


int go(int p, int gol, int zag, int mid, int ata){
    if ( gol >= 1 && zag >=4  && mid >= 4 && ata >= 2 ){
        return custo();
    }
    if(p >= jogadores.size() ) {
        return -inf;
    } 
    int r = -inf;
    if(gol == 0 ){
        if(jogadores[p].pos != 0 ) return -inf;
        myteam.pb(jogadores[p].jogador);
        r = max(r, go(p+1, 1, zag, mid, ata) );
        myteam.pop_back();
        r = max(r, go(p+1, 0, zag, mid, ata) );        
        return r;
    }
    if(zag < 4 ) {
        if(jogadores[p].pos == 0 ) return go(p+1, gol, zag, mid, ata);
        if(jogadores[p].pos > 1) return -inf;
        myteam.pb(jogadores[p].jogador);
        r = max(r, go(p+1, gol, zag+1, mid, ata) );
        myteam.pop_back();
        r = max(r, go(p+1, gol, zag, mid, ata) );         
        return r;
    }
    if(mid < 4 ) {
        if(jogadores[p].pos < 2 ) return go(p+1, gol, zag, mid, ata);
        if(jogadores[p].pos >2) return -inf;
        myteam.pb(jogadores[p].jogador);
        r = max(r, go(p+1, gol, zag, mid+1, ata) );
        myteam.pop_back();
        r = max(r, go(p+1, gol, zag, mid, ata) );         
        return r;
    }
    if(ata < 2 ) {
        
        if(jogadores[p].pos < 3 ) return go(p+1, gol, zag, mid, ata);
        if(jogadores[p].pos >3) return -inf;
       // if(jogadores[p].jogador == 21) printf("Tentando agora\n");
        myteam.pb(jogadores[p].jogador);
        r = max(r, go(p+1, gol, zag, mid, ata+1) );
        myteam.pop_back();
        r = max(r, go(p+1, gol, zag, mid, ata) );         
        return r;
    }    
    return -inf;
}


int main(){
    int val;

    int j1, j2;
    while(scanf("%s %d %s", str1, &val, str2) == 3 ) {
        mst(matrix, 0);
        mst(matrix_custo, 0);
        mymap.clear();
        jogadores.clear();
        myteam.clear();
        NEXT = 1;
        j1 = get(str1); j2 = getPos(str2);
        matrix_custo[j1] = val;
        jogadores.pb(tripla(j1, j2, val ) );

                
        fr(i,0,22){
            scanf("%s %d %s", str1, &val, str2);
            j1 = get(str1); j2 = getPos(str2);
            jogadores.pb( tripla(j1, j2, val)  ) ;
            matrix_custo[j1] = val;
            
        }
        sort(jogadores.begin(), jogadores.end());
        
        int q;
        sc1(q);

        while(q--){
            scanf("%s %s %d", str1, str2, &val);
            j1 = get(str1); j2 = get(str2);
           // printf("j1 %d j2 %d odeia %d\n", j1, j2, val);
            matrix[j1][j2] += val;
            matrix[j2][j1] += val;       
        }
        
       
         int r = go(0, 0, 0,0,0);
         if(r <= -inf ) printf("impossible\n");
         else printf("%d\n", r);
         //pv(v2, x);
         myteam = v2;
       //  printf("%d | %d %d \n", custo(), get("Pirlo"), get("Quagliarella") );
        
    }


	
	return 0;
}









