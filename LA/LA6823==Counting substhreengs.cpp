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


ll arr[1000005][5];


string line;
ll ans;
int main (int argc, char const* argv[]) {
	int len, k;
	while( getline( cin, line ) ){
		len = line.length();
		ans = 0;
		fr(i,0,len){
			if(!isdigit(line[i]))continue;
			int j;
			mst(arr[i], 0);
			k = line[i]-'0';
			if(k%3 == 0 ) ans++;
			arr[i][k%3]++;
			for(j = i+1; j < len && isdigit(line[j]); j++ ){
				k = line[j]-'0';
				int d = k%3;
				fr(l,0,3){
					arr[j][ (d+l)%3 ] =arr[j-1][l];
				}
				//if(0)fr(l,0,3){
				//	printf("%lld ", arr[j][l]);
				//}
				//_
				arr[j][d]++;				
				ans += arr[j][0];
			}
			//printf("digito de %d ate %d\n", i, j-1);
			i = j-1;
		}
		printf("%lld\n", ans);
	}	

	return 0;
}











