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
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

string input;
string code;

int pre[10000];
int dois[10000];

int main (int argc, char *argv[]) {
	code = "CODEFORCES";
	getline(cin,input);

	int j = 0;
	int m1 = 0, m2 = 0;
	for(int i=0; i < input.length() && j < code.length(); i++, j++){
		if(input[i] != code[j]) break;
		pre[i] = (i+1);
		m1 = max(m1, pre[i]);
	}
	j = code.length()-1;
	int cnt = 1;
	for(int  i = input.length()-1;i>=0 && j >= 0; i--, j--, cnt++){
		if(input[i] != code[j]) break;
		dois[i] = cnt;
		m2= max(m2, dois[i]);
		
	}	
 //	cout << "M1: " << m1 << " M2: " << m2 << endl;
	if(m1+m2 >= code.length()  || m1==code.length() || m2==code.length()) printf("YES\n");
	else printf("NO\n");
	
	
	
	return 0;
}


