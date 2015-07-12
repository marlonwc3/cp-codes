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
#define oi(x) cout << "Oi[" << x << "]" << endl
#define nd second
#define EPS 1e-8
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<char, int> ci;



string str;
int l[200010], r[200010], dead[200010];
bool is(int a, int b){
	if( a >= 0 && b >= 0 ) return (str[a] == '1' && str[b] == '0') || (str[a] == '0' && str[b] == '1');
	return 0;
}
int findl(int a){
	if(a < 0 || !dead[a] ) return a;
	return l[a] = findl(l[a]);
}
int findr(int a){
	if(a < 0 || !dead[a] ) return a;
	return r[a] = findr(r[a]);
}

int main (int argc, char const* argv[]){
	int n;
	sc1(n); getline(cin, str);
	getline(cin,str);
	int len = str.length();
	//printf("len: %d\n", len);
	fr(i,0,len) l[i] = i-1, r[i] = i+1;
	r[len-1] = -1;
	
	
	int ans = len;
	int a, b;
	if(len == 1 ) printf("1\n");
	else{
		fr(i,0,len){
			//printf("Start i: %d\n", i);
			a = findl(l[i]);
			//oi(a);

			if(!dead[i]){
				b = i;
			}
			else{
				b = findr(i);
			}
			//printf("i: %d | a: %d | b: %d \n", i, a, b);			
			int aux = ans;
			if(is(a,b)){
				dead[a] = 1; dead[b] = 1;
				//printf("Deads!\n");
				r[a] = findr(b);
				l[b] = findl(a);	
				ans -= 2;
				//oi(ans);
				//i--;
			}			
			if(ans < 0 ) {
				printf("i: %d | ans: %d | aux: %d | a: %d | b: %d \n", i, ans , aux,a,b); 
				
			//	assert(false);
			}			
		}
	//	ans = abs(ans);
		printf("%d\n", ans);
		
		
		
		
	}
		
	return 0;
}

