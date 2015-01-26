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

map<ii, int> mymap;

char line[100000];
int main(int argc, char const *argv[]) {
    ii p1 = mp(0,0);
    ii p2 = mp(1,1);
    ii p3 = mp(0,1);
    ii p4 = mp(1,0);
    

    int t;
    char c1, c2 , a, b;
    sc1(t); 
    gets(line);
    while(t--){ 
        gets(line);
        mymap.clear();
        char *pch = strtok(line, " ");
        int cnt = 0;

        while( pch != NULL ){
            a = ( pch[0] =='F' );
            b = ( pch[1] =='F' );
            cnt++;
            if(( !a && !b) ||(a && b) ){
                mymap[mp(1,0)]=0;
                mymap[mp(0,1)]=0;
                mymap[mp(a,b)]++;
            }
            else {
                if( ! (mymap[p1] || mymap[p2]) ){
                    mymap[mp(a,b)] =1 ;
                }
            }
            pch = strtok(NULL, " ");
        }
        bool ok  = cnt>1 ;
        if(mymap[p3] && mymap[p4]  )  ok = 0;
        else if ( mymap[p1] != mymap[p2] )  ok = 0;
        if( ok) printf("LOOP\n");
        else printf("NO LOOP\n");

    }   



    return 0;
}