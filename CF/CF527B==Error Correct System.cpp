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


struct lol {
	char a, b; int p;
	lol(){}
	lol(char _a, char _b, int _p){ a=_a, b=_b, p=_p;}
	bool operator < (const lol &l) const{
		if(a!=l.a) return a < l.a;
		if(b!=l.b) return b < l.b;
		return p < l.p;
	} 
	bool operator == (lol l){
		return a == l.a && b == l.b && p == l.p;
	}

};
set<lol> myset;

vi matrix[300];

string s1,s2; int n;
int main (int argc, char const* argv[]) {
	sc1(n); getline(cin,s1);
	getline(cin,s1); getline(cin,s2);

	fr(i,0,n){
		if(s1[i] != s2[i]){
		 	myset.insert(lol(s1[i], s2[i], i) );
		 	if(matrix[s1[i]].size() < 2 ) {
		 		matrix[s1[i]].pb(i);
		 		if(matrix[s1[i]].size() == 2 ){ sort(matrix[s1[i]].begin(), matrix[s1[i]].end()); }
		 	}
		 }
	}
	bool ok = 0;
	lol l, l2, l_b, l_u;
	char a, b; int p1, p2;
	set<lol>::iterator it_b, it_u;
	for(set<lol>::iterator it = myset.begin(); it != myset.end(); it++ ){
		l = (*it);
		a = l.a, b = l.b, p1 = l.p;
		l2 = lol(b, a, inf);
		it_b = myset.lower_bound(l2);
		if(it_b != myset.end() ){
			l_b = *it_b;
			if(! (l_b == l )  && l_b.a == l2.a && l_b.b == l2.b ){
				p2 = l_b.p;  ok = 1;
				//printf("ok 1\n");				
				break;
			}
			
		}
		l2 = lol(b, a, -inf);		
		it_u = myset.upper_bound(l2);
		if(it_u != myset.end() ) {
			l_u = *it_u;
			if(! (l_u == l) && l_u.a == l2.a && l_u.b == l2.b ){
				p2 = l_u.p;  ok =1;
				//printf("ok 2\n");
				break;
			}			
		}
	}
	if(!ok){
		char ch;
		fr(i,0,n){
			if(s1[i]==s2[i]) continue;
			ch = s2[i];
			fr(j,0,matrix[ch].size()){
				if(matrix[ch][j] == i) continue;
				p1 = i; p2 = matrix[ch][j]; ok = 1; 
				//printf("ok 3\n");				
				break;
			}
		
		}
	}
	
	if(ok){
		swap(s1[p1], s1[p2]);
		p1++; p2++;
	}
	else { p1=p2=-1;}
	int sum = 0;
	fr(i,0,n){ sum += s1[i] != s2[i]; }
	//printf("ok: %d\n", ok);
	printf("%d\n%d %d\n", sum, p1, p2);
	
	
	
	
	
	
	return 0;
}



