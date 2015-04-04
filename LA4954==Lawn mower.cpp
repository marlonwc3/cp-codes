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
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;

typedef pair<double, double> pd;

int cmp(double a, double b){
    if(fabs(a-b) <= EPS ) return 0;
    return (a>b) ? 1 : - 1;
}

bool mycmp(pd a, pd b){
    if( cmp(a.st , b.st) == 0 ){
        return cmp(a.nd , b.nd) == -1;
    }
    return cmp(a.st , b.st) == -1;
}


int main (int argc, char const* argv[]) {
    vector<pd> v;
    int nx, ny;
    double w;
    double k;
    while(1){
        scanf("%d %d %lf", &nx, &ny, &w); if(!nx && !ny && cmp(w, 0.0) == 0 ) break;
        
        double a, b;
        bool ok = 1;
        v.clear();
        fr(i,0,nx){
            scanf("%lf", &k);
            v.pb(mp(k - (w/2.0), k + (w/2.0) ) );
        }
        sort(v.begin(), v.end(), mycmp);
//        a = v[i].st, b = v[i].nd;
        pd p = v[0];
        fr(i,1,v.size()){
            if(cmp(v[i].st , p.nd ) <= 0) {
                p.nd = max (p.nd, v[i].nd);
            }
            else{
                p = v[i];
            }
        }
        //printf("1 encontoru %lf %lf\n", p.st, p.nd);
        ok = ok && (cmp(p.st, 0 ) <= 0  && cmp(p.nd, 75)>=0 );
        
        
        
        v.clear();
        fr(i,0,ny){
            scanf("%lf", &k);
            v.pb(mp(k - (w/2.0), k + (w/2.0) ) );
        }
        sort(v.begin(), v.end(), mycmp);
//        a = v[i].st, b = v[i].nd;
        p = v[0];
        fr(i,1,v.size()){
            if(cmp(v[i].st , p.nd ) <= 0) {
                p.nd = max(p.nd, v[i].nd);
            }
            else{
                p = v[i];
            }
        }
        
       // printf("2 encontoru %lf %lf\n", p.st, p.nd);
        ok = ok && (cmp(p.st, 0 ) <= 0  && cmp(p.nd, 100)>=0 );
        
        
        if(ok) printf("YES\n");
        else printf("NO\n");
        
    }
    
    
    
    return 0;
}








