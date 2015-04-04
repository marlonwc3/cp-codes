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


typedef pair<int, string> pis;

bool mycmp(pis a, pis b){
	if( a.st < b.st ) return 1;
	if( a.st > b.st ) return 0;
	//printf("empate %s %s\n", a.nd.c_str(), b.nd.c_str() );
	int len = min(a.nd.length(), b.nd.length() );
	fr(i,0,len){
		
		if( tolower(a.nd[i]) > tolower(b.nd[i]) ){ 
			//printf("vence a %c %c\n", a.nd[i], b.nd[i]);
			return 1; 
		}
		if( tolower(a.nd[i]) < tolower(b.nd[i]) ){
			//printf("vence b %c %c\n", a.nd[i], b.nd[i]);		
			 return 0; 
		}		
	}
	return 0;
}


int main (int argc, char const* argv[]) {
	int n, t=0;
	vi v;
	int k;
	vector<pis> vs;
	while(1){
		vs.clear();
		sc1(n);
		iz(n);
		string line;
		t++;
		fr(i,0,n){
			getline(cin,line);
			getline(cin,line);
			v.clear();
			fr(i,0,12){
				sc1(k);
				v.pb(k);
			}
			int sum =0;
			sort(v.begin(), v.end());
			fe(i,1,10){
				sum+=v[i];
			}
			vs.pb(mp(sum , line) );
			
		}
		
		sort(vs.begin(), vs.end(), mycmp);
		printf("Teste %d\n", t);
		printf("1 %d %s\n", vs.back().st, vs.back().nd.c_str() );
		int j =1;
		int last = vs.back().st;
		for(int i=vs.size()-2, l = 2; i>=0; i--, l++){
			int d;
			if( vs[i].st != last ) {		
				d = l;
				j = l;
			}
			else{
				d = j;
			}
			last = vs[i].st;
			printf("%d %d %s\n", d, vs[i].st, vs[i].nd.c_str() );
		}
		_
	}


	
	return 0;
}




