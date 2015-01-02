#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
using namespace std;
typedef vector<int> vi;
//typedef long long int lld;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<lld> vlld;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;
 
lld m = 2147483647;
bool val(lld a){
    return a>0 && a <= m;
}
int main (int argc, char const* argv[]) {
   
    set<lld> s;
    set<lld>::iterator it;
   
    lld a, b, c, w;
 
    fr(i,0,32) fr(j,0, 20) fr(k,0,14) {
        a = pow(2.0, i);
        b = pow(3.0, j);
        c = pow(5.0, k);       
        if(val(a) ) s.insert(a);
        if(val(b) ) s.insert(b);
        if(val(c) ) s.insert(c);
        w = a*b;
        if(val(w) ) s.insert(w);
        w = a*c;
        if(val(w)) s.insert(w);
        w = b*c;
        if(val(w) ) s.insert(w);
        w = a*b*c;
        if(val(w) ) s.insert(w); 
    }
    int cont =0 ;
    for(it = s.begin(); it != s.end() && cont < 1500; it++, cont++){
        a = *it;
    }
 
     printf("The 1500'th ugly number is %lld.\n", a);
   
   
}
