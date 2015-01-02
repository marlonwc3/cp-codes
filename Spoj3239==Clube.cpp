
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
bool cmp(int a, int b) { return a>b;}

int l;
int tab[2][10005];
vi v;

int foo(int a, int b, bool t){ // a*100/l  de tamanho b
	int val, s = v.size();
	if ( (a*100)%l ) return inf;
	int qt = (a*100)/l, cont=0, i=0; // qt de b
	int d;
	while(1){
		if(  i >= s || !qt ) break; 
		val = v[i];
		if ( val > b ) goto fim;
		if ( !tab[t][val] ) goto fim;
		if ( val == b ) {
			tab[t][val]--; cont++; qt--;
			i--;
			goto fim;
		}
		d = b - val; 
		if ( ( d==val && tab[t][d] < 2) || !tab[t][d]  ) goto fim;
		tab[t][d]--;
		tab[t][val]--;
		cont += 2; qt--;
		continue;	
		fim:;
		i++;
	}
	if(!qt) return cont;
	return inf;	
}

int main (int argc, char const* argv[]) {
	int m, n, k;
	int x, r;
	while(1){
		sc2(m,n);
		if(!m && !n ) break;
		r = inf;
		v.clear();
		mst(tab,0);
		sc2(l, k);
		fr(i,0,k){
			sc1(x); 
			if( !tab[0][x] ) v.pb(x);
			tab[0][x]++;
			tab[1][x]++;
		}
		sort(v.begin(), v.end(), cmp);
		r = min(r, foo(m,n, 0) );
		r = min(r, foo(n,m, 1) );
		if( r>=inf) {
			printf("impossivel\n");
		}
		else printf("%d\n", r);


			
	}
	
	
	return 0;
}



