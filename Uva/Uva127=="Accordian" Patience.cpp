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


typedef pair<char, char> cc;
vector< stack<cc> > vs;




void go(){
    char c1, c2;
    bool mudou = 1;
    while(mudou){
        mudou = 0;
        for(int i = 0; i< vs.size(); i++ )  {
            c1 = vs[i].top().st, c2 = vs[i].top().nd;
            bool ok =0 ;
            if( i - 3 >= 0 && !vs[i-3].empty() ) {
                if( vs[i-3].top().st == c1 || vs[i-3].top().nd ==c2  ){
                    vs[i].pop();
                    if(vs[i].empty()){ vs.erase(vs.begin() +i ); }
                    vs[i-3].push(mp(c1,c2));
                    mudou = 1;
                    i = i-4;
                    ok = 1;
                }
            }
            if(!ok) if( i - 1 >= 0 && !vs[i-1].empty() ){
                if( vs[i-1].top().st == c1 || vs[i-1].top().nd ==c2  ){
                    vs[i].pop();
                    if(vs[i].empty()){ vs.erase(vs.begin() +i ); }
                    vs[i-1].push(mp(c1,c2));
                    mudou = 1;
                    i = i-2;
                    ok = 1;
                }                
            }          
        }
    }
}

int main(int argc, char const *argv[]) {
    char line[10000];
    int id;
    stack<cc> mystack;
    while(1){
        gets(line);
        if(line[0] =='#') break;
        vs.clear();
        id=0;        
        char *pch = strtok(line, " ");
        while(pch!= NULL){
            mystack = stack<cc>();
            mystack.push( mp(pch[0], pch[1]) );
            vs.pb(mystack);
            pch = strtok(NULL, " ");
            id++;
        }
        gets(line);
        pch = strtok(line, " ");
        while(pch!= NULL){
            mystack = stack<cc>();
            mystack.push( mp(pch[0], pch[1]) );
            vs.pb(mystack);
            pch = strtok(NULL, " ");
            id++;
        }        
        go();
        vi v;
        int cnt = 0;
        fr(i,0,vs.size()){
            if(vs[i].empty()) continue;
            cnt++;
            v.pb(vs[i].size());
        }
        printf("%d pile", cnt);
        if( cnt >  1) printf("s");
        printf(" remaining:");
        fr(i,0,v.size()) printf(" %d", v[i]);
        _
    }  
    return 0;
}