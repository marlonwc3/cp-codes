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

void toBin(ll n){
	if(!n) {_ return;}
	printf("%lld", n%2) ;
	toBin(n/2);
}


const ll MOD = 1000000007;

int main(int argc, char const *argv[]) {
	//toBin(100005);
	int caso;
	string line;
	sc1(caso); getline(cin,line);
	
	int len;
	fe(t,1,caso){
		getline(cin,line);
		int p1, p2, len, total, p, d1, d2;
		total = len = line.length();
		p2 = len/2;
		p1 = len%2==1 ? p2 : p2-1;
		ll res = 0;
		while( total > 0 ) {
			d1 = p1+1;
			d2 = len - p2;
			//printf("res: %lld | p1: %d | p2: %d | total: %d | d1: %d | d2: %d\n",res, p1, p2, total, d1, d2);
			if(total%2 == 1) {
				if( d1 > d2) p = p1;
				else p = p2;
			}
			else{
				if( line[p1] > line[p2]  )p = p1;
				else if (line[p2] > line[p1]) p = p2;
				else{
					if( d1 > d2) p = p1;
					else p = p2;
				}
			}	
			//printf("p: %d\n",p );
			res = ((res*2)%MOD + (line[p]-'0'))%MOD;
			if(p1==p2){ p1--; p2++; }
			else if(p==p1) p1--;
			else p2++;
			total--;
		}

		printf("Case #%d: %lld\n", t, res);
	}




	return 0;
}
