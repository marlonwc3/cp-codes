#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%lld", &a)
#define sc2(a,b) scanf("%lld %lld", &a, &b)
#define sc3(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%lld ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%lld %lld ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define oi(x) cout <<"[Oi | " << x << "]"<<endl;
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef  long long ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
const long double EPS = 1e-6;


ll A1, A2, A3, A4, B1, B2, C;
	
ll bs(ll lo, ll hi, const ll &H){
	if(lo +1 >= hi ) return -linf;
	ll mid = (lo+hi)/2;	
	if( H - mid*C <= B2) return max(mid, bs(mid,hi, H));
	return bs(lo, mid, H);
}

ll f(ll X, ll Y ){
	ll H = A1*X*Y + A2*X + A3*Y + A4;
	if( H > B1){
		
		if(1){
			ll K = bs(-1, linf, H);
			K =  (H-B2+C-1)/C;
			H -= K*C;
		}
	}
	
	return H;
}


ll X,Y;
void gen(){
	ll aux, aux2;
	vll v; v.pb(X); v.pb(Y);
	aux = X, aux2= Y;
	fr(i,0,10){ v.pb(f(aux, aux2)); aux = Y; aux2 = v.back(); }
	pv(v,x);
}


int main() {

	scanf("%lld %lld %lld %lld %lld %lld %lld", &A1, &A2, &A3, &A4, &B1, &B2, &C);
	scanf("%lld %lld", &X, &Y); 
	//gen();
	//cout << f(1,3) << endl;
	//return 0;
	
	
	if(0 && X==Y && Y == f(X,Y)) printf("0 2\n");	
	else {

		ll a = X, b = Y, c = X,d = Y, aux, aux2;
		ll it = 0;
		
		
		while((a != c || b != d) || it == 0){
		//	printf("%lld | %lld \n", b, d);
			aux = f(a,b);
			//if(it <= 10 ) printf("a: %lld | b: %lld | aux: %lld\n" ,a , b, aux);			
			a = b; b = aux;
			aux2 = f(c,d);
			aux = f(d,aux2);
			c = aux2; d = aux;
			it++;
		}
		it = 1;
		c = X, d = Y;
		//printf("a: %lld | b: %lld\n" , a,b);
		while(c != a || d != b){
			aux = f(a,b);
			a = b; b = aux;
			
			aux = f(c,d);
			c = d; d = aux;
			it++;			
		}
		//it++;
		//printf("it: %lld\n", it);
		ll len = 0;
		c = a; d = b;
		while(c != a || d != b || !len){
			aux = f(c,d);
			c = d; d = aux;
			len++;			
		}	
		//fr(i,0,min(10, (int(v.size())))) printf("%lld  ",v[i] ); _
		printf("%lld %lld\n", it, len);
		
		
	}
	
	
	
	
	
	return 0;
}


















