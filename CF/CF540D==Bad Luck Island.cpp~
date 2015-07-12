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
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;



struct tripla{
	double p1, p2, p3;
	tripla(){}
	tripla(double _p1, double _p2, double _p3){p1=_p1, p2=_p2, p3=_p3;}
	void add(tripla t){
		p1 += t.p1; p2 += t.p2; p3 += t.p3;
	}
};


tripla pd[105][105][105];
bool passo[105][105][105];


         // pedra, tesoura, papel
tripla go(int a, int b, int c){
	if(a==0 && b== 0 && c== 0) return tripla(0,0,0);
	if(a==0 && b== 0) return tripla(0,0,1);
	if(a==0 && c== 0) return tripla(0,1,0);	
	if(b==0 && c== 0) return tripla(1,0,0);
	if(passo[a][b][c]) return pd[a][b][c];
	tripla r = tripla(0,0,0), ret;
	double p;
	if(a && b ) {
		ret = go(a, b-1, c);
		p = (double(a*b))/(a*b + b*c + a*c);
		ret.p1 *= p;
		ret.p2 *= p;
		ret.p3 *= p;
		
		r.add(ret);
	}
	if(b && c ) {
		ret = go(a, b, c-1);
		p = (double(b*c))/(a*b + b*c + a*c);
		ret.p1 *= p;
		ret.p2 *= p;
		ret.p3 *= p;
		
		r.add(ret);
	}	
	if(a && c ) {
		ret = go(a-1, b, c);
		p = (double(a*c))/(a*b + b*c + a*c);
		ret.p1 *= p;
		ret.p2 *= p;
		ret.p3 *= p;
		
		r.add(ret);
	}	
	passo[a][b][c] = 1;
	pd[a][b][c] =r;
	return r;
}



int main (int argc, char const* argv[]){
	mst(passo, 0);
	int a, b, c;
	sc3(a,b,c);
	tripla r = go(a,b,c);
	printf("%.12lf %.12lf %.12lf\n", r.p1, r.p2, r.p3);
	
	
	
	return 0;
}


