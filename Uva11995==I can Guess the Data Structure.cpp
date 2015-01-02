#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
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


struct CMP {
	bool operator () (int a, int b){
		return a < b;
	}
};

priority_queue<int, vector<int>, CMP > pq;
queue<int> q;
stack<int> s;
bool m[5];
int main (int argc, char const* argv[]) {
	int n, a,b, type, x, y, z;
	while(sc1(n)==1){
		q = queue<int>();
		s = stack<int>();
		pq = priority_queue<int, vector<int>, CMP>();
		mst(m,1);
		while(n--){
			sc2(a,b);
			if(a==1){
				q.push(b);
				s.push(b);
				pq.push(b);
			}
			else {
				if(q.empty() ) {m[0]=0; }
				else {
					if(q.front() != b) {m[0] = 0;}
					q.pop();
				}
				if( s.empty()  ) { m[1]= 0;}
				else {
					if(s.top() != b) {m[1] = 0; }
					s.pop();
				}
				if(pq.empty() ) { m[2]= 0; }
				else {
					if(pq.top() != b) {m[2] = 0;}
					pq.pop(); 
				}
			}
		}
		if(!m[0] && !m[1] && !m[2]) {
			printf("impossible\n");

		} 
		else if (m[0] && !m[1] && !m[2]){
			printf("queue\n");
		}
		else if(m[1] && !m[0] && !m[2]){
			printf("stack\n");
		} 
		else if(m[2] && !m[0] && !m[1]){
			printf("priority queue\n");
		}
		else {
			printf("not sure\n");			
		}
		
	}
	
	return 0;
}














