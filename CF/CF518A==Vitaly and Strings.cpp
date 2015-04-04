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

bool is(char ch){
	return ch >= 'a' && ch <= 'z';
}

bool menor(string s1, string s2){
	int l = s1.length();
	fr(i,0,l){
		if(s1[i] == s2[i]) continue;
		if(s1[i] < s2[i] ) return 1;
		return 0;
	}
	return 0;
}

int main (int argc, char const* argv[]) {
//	printf("g %d h %d\n", 'g', 'h');

	getline(cin, s1);
	getline(cin, s2);
	bool ok = 0;
	int len = s1.length();
	string s3;
	fr(i,0,len){
		s3  = "" +s1;
		s3[i]++;
		if(is(s3[i]) && s3 > s1 && s3 < s2  ){ ok = 1; break;}
		s3[i]-=2;
		if(is(s3[i]) && s3 > s1 && s3 < s2  ){ ok = 1; break;}		
		
		s3 = "" + s2;
		s3[i]++;
		if(is(s3[i]) && s3 > s1 && s3 < s2  ){ ok = 1; break;}
		s3[i]-=2;
		if(is(s3[i]) && s3 > s1 && s3 < s2  ){ ok = 1; break;}		
					
	
	}
	
	if(!ok) printf("No such string\n");
	else printf("%s\n", s3.c_str());
	return 0;
}

