#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef vector<lld> vlld;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<int> si;

vi nums;
sii difs;
vi v;
int n, m;

sii::iterator it;

bool cmp (const ii &a, const ii &b) {
	return a.nd < b.nd;
}

lld solve(){
	sort(nums.begin(), nums.end());
	if(m==1) return nums[n-1] - nums[0];
	
	
	int d, k = 0;
	fr(i, 0, n-1){
		d = nums[i+1] - nums[i];
		if( k < m- 1 ){ difs.insert( mp( d, i )  ); k++; }
		else {
			it = difs.begin();
			if( (*it).st< d ) {
				difs.erase(it); 
				difs.insert(mp(d,i));
			}
		}	
	}
	
	for(it = difs.begin(); it != difs.end(); it++){
		v.pb( (*it).nd );
	}
	sort(v.begin(), v.end());

	int ini = 0; lld res = 0;
	for(int i= 0; i < m-1; i++){
		k = v[i]; //  de ini até inclusive k 
		res += nums[k] - nums[ini];
		ini = k+1;
	}	
	k = n-1;
	res += nums[k] - nums[ini];
	
	
	return res;
		
	


}

int main (int argc, char const* argv[]) {
	int t, k ;  lld res;
	sc1(t);
	t++;
	
	fr(i,1,t){
		nums.clear(); difs.clear();
		v.clear();	
		sc2(n,m);

		fr(j, 0, n){
			sc1(k); nums.pb(k);
		}
		res = solve();
		printf("Case #%d: %lld\n", i, res);
		
		
	}	
	
	
	return 0;
}











