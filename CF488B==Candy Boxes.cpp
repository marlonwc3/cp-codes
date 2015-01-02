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


vi param;
vi v;
vi res;
int n;	
vi aux;
bool can(){	
	aux.clear();
	fr(i,0,v.size())aux.pb(v[i]);
	fr(i,0,param.size()) aux.pb(param[i]);
	sort(aux.begin(), aux.end());
	double m = accumulate(aux.begin(), aux.end(), 0)/4.0, w;
	w = aux[3]-aux[0];
	if(w!=m) return 0;
	w = (aux[2]+aux[1])/2.0;
	if(w!=m) return 0;
	return 1;
}

int main (int argc, char const* argv[]){ 	
	sc1(n);
	int k;
	fr(i,0,n){
		sc1(k);
		v.pb(k);
	}

	bool ok = 0;
	if(n==0) {
		ok = 1;
		res.pb(1); res.pb(1); res.pb(3); res.pb(3);
	}
	else if(n==1){
		ok = 1;
		res.pb(v[0]); res.pb(3*v[0]); res.pb(3*v[0]);  
	}
	else if ( n== 4) {
		ok = can();
	}
	else if (n==3){
		fr(i,1,1000001){
			param.pb(i);
			if(can()){ res.pb(i); ok =1; break; }
			param.pop_back();
		}
	}
	else { // n==2
	
		fr(i,1,501){
			param.pb(i);
			fr(j,1,501){
				param.pb(j);
				if(can()){ res.pb(i); res.pb(j); ok =1; goto fim; }
				param.pop_back();
			}
			param.pop_back();
		}
		int a = min(v[0],v[1]);
		int b = max(v[0],v[1]);
		int d = 2*a + b, x;
		fr(i,1, 1000001){ // y
			x = 2*i - d;
			if( x >= 1 && x <= 1000001);
			param.pb(i);
			param.pb(x);
			if(can()){
				res.pb(i); res.pb(x);
				ok =1; break;
			}
			param.pop_back(); param.pop_back();
		}	
			
		
	}
	
	fim:;
	sort(res.begin(), res.end());
	if(ok){
		printf("YES\n");
		fr(i,0,res.size()){
			printf("%d\n", res[i]);
		}
	}
	else printf("NO\n");
	

	return 0;
}











