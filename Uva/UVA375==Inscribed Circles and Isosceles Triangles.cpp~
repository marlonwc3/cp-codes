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
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second	
#define EPS 1e-12
#define oi(__) cout << "Oi ["<< __ << "]" << endl
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const long double PI = acos(-1);
const long double LIMIT =0.000001;

int mycmp(long double a, long double b = 0.0){
	if(fabs(a-b) <= EPS) return 0;
	return (a>b) ? 1 : -1;
}

char str[500], out[500];
int main (int argc, char const* argv[]){
	long double B, H, r,s = 0;
	int T;
	sc1(T);
	bool first = 1;
	while(T--){
		
		if(!first) _
		r = linf;
		s = 0;
		scanf("%Lf %Lf", &B, &H);	
		int it = 0;

		while(1){
			r = (B*tan(  atan( (2*H)/B )/2  ))/2;
			if(mycmp(r,LIMIT) <= 0 ) break;
			s += PI*r*2;
			B = ((H -2*r)*B)/H;
			H -= 2*r; 
		}
		printf("%13.6Lf\n", s);


		
		
			
		first = 0;
	}


	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
