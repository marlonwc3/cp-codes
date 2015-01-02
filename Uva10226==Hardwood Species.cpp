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

map<string, int> ms;
vector<string> vs;
int main (int argc, char const* argv[]) {
	int t, total, len, cnt;
	double res;
	bool first =1;
	string line;
	sc1(t);
	getline(cin,line);
	getline(cin,line);
	while(t--){
		ms.clear();
		vs.clear();
		total =0 ;
		if(!first) _ 
		while(1){
			getline(cin,line);
			//printf("line: %s\n", line.c_str());
			if(line.empty()) break;
			ms[line]++;
			total++;
			if (ms[line]==1){
				vs.pb(line);
			}
		}
		
		sort(vs.begin(), vs.end());
		len = vs.size();
		fr(i,0,len){
			line = vs[i];
			cnt = ms[line];
			res = ((100*cnt)+0.0)/total;
			printf("%s %.4lf\n", line.c_str() , res);
		}
		first = 0;
	}
	return 0;
}










