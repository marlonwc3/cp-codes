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

string a, b;
int arrA[105];
int arrB[105];


int main (int argc, char const* argv[]) {
	int n;
	
	int t, m;
	char l, card;
	getline(cin, a);	
	getline(cin, b);
	sc1(n);
	fr(i,0,n){
		scanf("%d %c %d %c", &t, &l, &m, &card);
		if(l=='h'){
			if(arrA[m] < 2) {
				arrA[m] += (card=='r') ? 2 :  1;
				if(arrA[m] >= 2) {
					printf("%s %d %d\n", a.c_str(), m, t);
				}
			}			
		}
		if(l=='a'){
			if(arrB[m] < 2 ){
				arrB[m] += (card =='r') ? 2 : 1;
				if(arrB[m] >= 2) {
					printf("%s %d %d\n", b.c_str(), m, t);
				}	
			}
		}
		
	
	}
	
	return 0;
}
