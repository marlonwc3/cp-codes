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

vi res;
int main (int argc, char const* argv[]) {
	int  t, p , cont, no, maior, len;
	string line;
	sc1(t);
	while(t--){	
		sc1(p);
		maior = inf;
		no = 0;
		getline(cin, line);
		res.clear();
		no = 0;
		while(p--){
			no++;
			cont = 0;
			getline(cin, line);			
			len = line.length();
			
			if(len && line[0] != 32){
				cont++;
				fr(i,0,len){
					if(line[i]==32) cont++;
				}
			}
			if(cont <= maior){
				if(cont<maior) {
					res.clear();
				}
				res.pb(no);
				maior = cont;
			}		
		}
		fr(i,0,res.size()){
			printf("%d", res[i]);
			if(i!=res.size()-1) printf(" ");
		}
		_
	
	}
	return 0;
}





















