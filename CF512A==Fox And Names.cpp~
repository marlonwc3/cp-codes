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


int g[350];
vi e[350];
bool mark[350];
vi topo;
void go(){
    queue<int> q;
    fe(i,'a', 'z'){
       // printf("c: %c -> %d\n", i, g[i]);
        if(!g[i]) q.push(i); 
    }
    int a, b, s;
   
    while(!q.empty()){
        a = q.front(); q.pop();
        s = e[a].size();
        topo.pb(a);
     //   printf("a : %d\n", a);
        mark[a] = 1;
        fr(i,0,s){
            b = e[a][i];
            if( g[b] <=  0 ) continue;
            g[b]--;
            if(!g[b]) q.push(b);
        }
    }
}







int main (int argc, char const* argv[]) {
    int n, len, len2;
    string line, bef;
    sc1(n); getline(cin,line);
    vector<string> vs;
    getline(cin,line);
    vs.pb(line);
     bool ok = 1;   
    fr(i,1,n){
        getline(cin,line);              
        len = line.length();
        bef = vs[i-1];
        len2 = bef.length();
        int len3 = min(len,len2);
        
        
       // printf("line %s | s2 %s  | %d %d \n", line.c_str(), bef.c_str(), len, len2);
        bool achou = 0 ;
        fr(j,0,len3){
           if(line[j] == bef[j] ) continue;
           e[bef[j]].pb( line[j] );
           g[line[j]]++;
           achou = 1;
           break;
       //    printf("1\n");
        }
        
        if(!achou && (len2 > len) ) ok = 0;
        
      //  printf("2 \n");
        
        
        vs.pb(line);
    
    
    
    }
    if(0) fe(i,'a', 'z'){
        printf("c: %c \n", i);
        fr(j, 0, e[i].size()){
            printf("%c ", e[i][j]);
        }
        _
    }    
        //printf("oi\n");
    go();
    if(0) fe(i,'a', 'z'){
        printf("c: %c -> %d\n", i, g[i]);
    }

    fe(i,'a', 'z') {
        ok  = ok && !g[i];
        if(!mark[i]) topo.pb(i);
    }
    if(!ok) printf("Impossible\n");
    else{
        fr(i,0,topo.size()){
            printf("%c", topo[i] );
            
        }
        _
        
    }
    
    
    return 0;
}



