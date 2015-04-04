#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-6
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



int rep[20010];
int off;
void init(int n){ fr(i,0,(2*n) +1) { rep[i]=i;  }   }
int find(int a) { return rep[a] = (rep[a]==a) ? a: find(rep[a]); }
void uni(int a, int b) { rep[find(a)] = find(b); }
bool iss(int a,int b){ return find(a)==find(b);}

int foo(int a){ return a + off;}

bool af(int a,int b){
	return iss(a, b);
}
bool ae(int a, int b){
	return iss(a ,foo(b) );
}

bool setf(int a,int b){
	if( ae(a,b) )  return 1;
	uni(a,b);
	uni(foo(a) , foo(b));
	return 0;
}

bool sete(int a, int b){
	if( af(a,b) ) return 1;
	uni(a, foo(b) );
	uni(b, foo(a) );
	return 0;
}




int main (int argc, char const* argv[]) {
	int n, a,b,c;
	sc1(n);
	off = n;
	init(n);
	bool ok;
	while(1){
		sc3(c,a,b); if(!c && !a && !b ) break;
		
		if(c==1){
			if( setf(a,b) )  printf("-1\n");
		}
		if(c==2){
			if( sete(a,b) ) printf("-1\n");
		}
		if(c==3 || c== 4){
			ok = (c==3) ? af(a,b) : ae(a,b);
			printf("%d\n", ok);
		
		}
		
	}
	
	
	return 0;	
}

