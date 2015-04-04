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
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;	

bool mark[2*100005];
int cnt[500];
string s1, s2;

int main (int argc, char const* argv[]) {
	getline(cin, s1);
	getline(cin, s2);	
	int l1, l2;
	l1 = s1.length(), l2 = s2.length();
	fr(i,0,l2){
		cnt[s2[i] ]++;
	}
	
	char ch;
	int r1 = 0, r2 =0 ;
	fr(i,0,l1){
		if( cnt[s1[i]]  )  {
			cnt[s1[i]]--;
			mark[i] = 1;
			r1++;
		}
	}
	
	fr(i,0,l1){
		if(mark[i]) continue;
		if(islower(s1[i])) ch = toupper(s1[i]);
		else ch = tolower(s1[i]);
		if( cnt[ch]  )  {
			cnt[ch]--;
			r2++;
		}
	}
	printf("%d %d\n", r1, r2);
	
	
	
	
	return 0;
}

