#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
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
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;
typedef long double lb;

vector<string> vs;
int n;
string rule;
string r;
int len;
void bt(int pt){
    if( pt >= len ){
        printf("%s\n", r.c_str());
        return;
    }
    string aux;
    if( rule[pt] == '#' ){
        fr(i,0,n){
            aux = r;
            r += vs[i];
            bt(pt+1);
            r = aux;
        }
    }
    else  if ( rule[pt] == '0'){
        fr(i,0,10){
            aux = r;
            r+= (i+'0');
            bt(pt+1);
            r = aux;
        }
    }


}


int main (int argc, char const* argv[]) {
    int m;
    char str[10000];
    while(sc1(n)==1){
        vs.clear();
        fr(i,0,n){
            scanf("%s", str);
            vs.pb(str);
        }
        sc1(m);
        printf("--\n");
        fr(i,0,m){
            scanf("%s", str);
            rule = str;
            len = rule.length();
            r = "";
            bt(0);
        }
    }
    
    
    return 0;
}

