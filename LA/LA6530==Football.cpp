#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
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
typedef pair<char, int> ci;
typedef long double lb;

bool cmp(int a,int b){
	return a>b;
}

int main (int argc, char const* argv[]) {
	int n,g, a,b,pt,s;
	vi v;
	while(sc2(n,g)==2){
		pt= 0;
		v.clear();
		fr(i,0,n){
			sc2(a,b);
			if(a>b) {
				pt+=3;
			}
			else {
				v.pb(a-b);
			}
		}
		sort(v.begin(), v.end(), cmp);
		s = v.size();
		
		fr(i,0,s){	
			if(g>0){
				a = abs(v[i]) + 1;
				if( a <= g) {
					pt+=3;
					g-=a;
				} 
				else {
					a--;
					if( a==g) {
						pt++;
						g=0;
					}
				}
			}
			else pt += (v[i]==0);
		}
		printf("%d\n", pt);
	}
	return 0;
}











