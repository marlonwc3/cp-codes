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
typedef pair<char, int> ci;






set<char> sc;
vi v;
string str;
int main (int argc, char const* argv[]){
	int k;
	sc1(k);
	getline(cin, str);
	getline(cin,str);
	int len = str.length();
	fr(i,0,len){
		if(!sc.count(str[i]) ){
			sc.insert(str[i]);
			v.pb(i);
		}
		if(v.size() == k ) break;
	}
	if( v.size()  != k ) printf("NO\n");
	else{
		printf("YES\n");
		//pv(v,x);
		v.pb(str.length());
		for(int i = 0; i < v.size() -1; i++){
			for(int j  = v[i]; j < v[i+1]; j++) printf("%c", str[j]);
			_
		}
	
	}


	
	return 0;
}

