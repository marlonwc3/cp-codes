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
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%lld ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <((a).size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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

#define MOD ll(1000000007)

#define MAX_SIZE (1<<20)
char str[MAX_SIZE]; 
int ptr; 
bool ok; 
double x; 

// funções f e g
ll f(double x) {
	return exp(x);
}
ll g(ll x, ll y){
	return atan2(x,y);
}


ll numero() {
	char *fim;
	ll r = strtod(str+ptr, &fim);
	if( fim-str == ptr ) ok = false;
	ptr = fim-str;
	return r;
}

ll expressao(); 

ll elemento() {
	ll X,Y;
	switch( str[ptr] ) {
	case '-':
		++ptr;
		return -elemento();
	case '(':
		++ptr;
		X = expressao();
		if( !ok ) return X;
		if( str[ptr++] != ')' ) ok = false;
		return X;
	case 'f':
		++ptr;
		if( str[ptr++] != '(' ) ok = false;
		X = expressao();
		if( !ok ) return X;
		if( str[ptr++] != ')' ) ok = false;
		return f(X);
	case 'g':
		++ptr;
		if( str[ptr++] != '(' ) ok = false;
		X = expressao();
		if( !ok ) return X;
		if( str[ptr++] != ',' ) ok = false;
		Y = expressao();
		if( !ok ) return Y;
		if( str[ptr++] != ')' ) ok = false;
		return g(X,Y);
	case 'x':
		++ptr;
		return x;
	default:
		return numero();
	}
}

// EXPO
ll expo() {
	ll e = elemento();
	if( str[ptr] == '^' ) {
		++ptr;
		e = ll(pow(e, expo()))%MOD;
	}
	return e;
}

// FATOR
ll fator() {
	// "acumulado"
	ll acc = expo();
	while( str[ptr] == '*' || str[ptr] == '/' ) {
		if( str[ptr] == '*' ) {
			++ptr;
			acc = (acc * expo())%MOD;
		} else { // '/'
//if(op==-2)return ( ll(trunc(double(a)/b)))%MOD; 		
			++ptr;
			acc = ll(  trunc(double(acc) / expo()) )%MOD;
		}
	}
	return acc;
}

// EXPRESSÃO
ll expressao() {
	// "acumulado"
	ll acc = fator();
	while( str[ptr] == '+' || str[ptr] == '-' ) {
		if( str[ptr] == '+' ) {
			++ptr;
			acc = (acc + fator())%MOD;
		} else { // '-'
		
			++ptr;
			acc = (acc - fator())%MOD;
		}
	}
	return acc;
}

ll avaliar(double x) {
	// init
	::x = x;
	ok = true;
	ptr = 0;
	ll r = expressao();
	ok &= str[ptr] == '\0';
	return r;
}


int main() {
	int caso;
	sc1(caso);
	fe(t,1,caso){
		scanf("%s", str);
		ll r = avaliar(0)%MOD; 
		if(r<0) r += MOD;
		printf("Case #%d: %lld\n", t, r);
	}
	
	return 0;
}


