#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef set<int> si;

//si s;

struct tower
{
	int h;
	int id;
	tower(){}
	tower(int _h, int _id){
		h=_h; id=_id;
	}
	
	bool operator < (const tower &t) const{
		return h < t.h;
	}	
};

//vi v;
vector<tower> v;
vii res;
int n, k, a, b;
void pv(){
	//fr(i,0,n) pf(v[i].h)
	//_

}

int main (int argc, char const* argv[]) {
	

	sc2(n, k);
	fr(i, 0, n) {
		sc1(a);
		v.pb(tower(a, i+1) );
	}

	
	int cont =0;
	int dif = inf, d;
	while(1){
	//	pv();
		if(cont >= k ) break;
		sort(v.begin(), v.end());
		//a = v[0];
		//b = v[n-1];
		d = fabs(v[n-1].h - v[0].h);
//	printf("ab-> ");	pf(a) pf(b) _
		dif = min(dif, d );
		if(d==0) break;
		if(v[n-1].id == v[0].id) continue;
		
		if(v[n-1].h>=1){
			res.pb(mp(v[n-1].id, v[0].id));
		//	printf("moving\n"); printf("%d %d\n", v[n-1].id, v[0].id);
			v[0].h++;
			v[n-1].h--;

//	printf("ab-> ");	pf(a) pf(b) _
		
			cont++;		
		}
	}
	
		sort(v.begin(), v.end());
		//a = v[0];
		//b = v[n-1];
		d = fabs(v[n-1].h - v[0].h);
//	printf("ab-> ");	pf(a) pf(b) _
		dif = min(dif, d );
	
	printf("%d %d\n", dif, cont);
	n = res.size();
	fr(i,0,n){
		printf("%d %d\n", res[i].first, res[i].second);
	}
	
	
	
	return 0;

}
