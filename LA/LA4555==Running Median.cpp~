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
#define oi(x) cout <<"Oi [" << x << "]" << endl
using namespace std;
template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

priority_queue<int, vector<int>, greater<int> > q2;
priority_queue<int> q1;
void fix(){
	if(abs(q1.size() - q2.size() ) >= 2 ) {
		if(q1.size() > q2.size() ) q2.push(q1.top()), q1.pop();
		else q1.push(q2.top()), q2.pop();
		fix();
	}
}


int main (int argc, char const* argv[]){
	int caso,x , N;
	sc1(caso);
	fe(t,1,caso){
		sc2(x, N);
		q2 = priority_queue<int, vector<int>, greater<int> >();
		q1 = priority_queue<int>();
		sc1(x);
		int cnt = 1;
		printf("%d %d\n", t, (N+1)/2);
		printf("%d", x);
		if(N >= 3) printf(" ");
		q2.push(x);  
		fr(i,1,N){
			sc1(x);
			if(x > q2.top() ) q2.push(x);
			else q1.push(x);
			fix();	
			if(i%2 == 0 ){
				if(q1.size() > q2.size() ) printf("%d", q1.top() );
				else printf("%d", q2.top() ) ;
				if(i != N-1 && cnt != 9 ) printf(" ");
				cnt++;
				if(cnt >= 10 ) { cnt = 0; _  }
			}

			
		}
		if(cnt) _	
	
	
	}
	
	return 0;
}







