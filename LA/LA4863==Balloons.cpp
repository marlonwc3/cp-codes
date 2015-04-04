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


int n, a, b;
ii v[1005];
int db[1005];
int da[1005];
int vk[1005];

ii getA(int k, int id){ // restok, custo
	ll w = da[id];
	if( k > a ){
		k-=a;
		w*=a;
		a =0;
	}
	else{
		a -= k;
		w *= k;
		k = 0;
	}
	return mp(k, w);
}
ii getB(int k, int id){ // restok, custo
	ll w = db[id];
	if( k > b ){
		k-=b;
		w*=b;
		b = 0;
	}
	else{
		b -= k;
		w *= k;
		k = 0;
	}
	return mp(k, w);
}

bool mycmp(ii a, ii b){
	if(a.st == b.st ) return a.nd < b.nd;
	return a.st > b.st;
	//return a.st < b.st;
}

int main (int argc, char const* argv[]) {
	int k, x, y, id;
	
	while(1){
		sc3(n,a,b); if(!n && !a && !b) break;
		fr(i,0,n){
			sc3(vk[i], x, y);
			v[i] = mp(abs(x-y), i);
			da[i] = x;
			db[i] = y;
		}
		sort(v, v+n, mycmp);
		//fr(i,0,n) printf("(%d %d) ", v[i].st, v[i].nd);
		//_
		
		int r = 0;
		fr(i,0,n){
			id = v[i].nd;
			k = vk[id];
			ii r1, r2;
//			printf("id: %d | a: %d | b: %d | r: %d \n",id, a, b, r);
			if ( da[id] <= db[id]  ) {
				r1 = getA(k, id);
				k = r1.st, r+=r1.nd;
//				printf("pegou de A| k: %d\n",k);								
				r2 = getB(k, id);
				k = r2.st, r+=r2.nd;
			}
			else{
				r2 = getB(k, id);
				k = r2.st, r+=r2.nd;
//				printf("pegou de B| k: %d\n",k);						
				r1 = getA(k, id);
				k = r1.st, r+=r1.nd;
			}

		
	
		}
		printf("%d\n", r);		
	
	}
	
	
	
	
	return 0;
}

















