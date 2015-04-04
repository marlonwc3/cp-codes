#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define iz(b) if(b==0) { break; }
#define pf(a) printf("%d ", a);
#define pfc(c,a) printf("%c -> %d ", c, a);
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=a; i < b; i++)
#define mp(a,b) make_pair(a,b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
using namespace std;
typedef vector<int> vi;
typedef long long int lld;
typedef pair<int,int> ii; // first==no, second==wieght
typedef vector<ii> vii;
typedef set<int> si;

vi v;
int p;
bool nums[1000005];
ii res;
void go(){
	sort(v.begin(), v.end());	
	int i = v.size()-1, k, f;
	while(i>=0){
		k = v[i];
		f = p-k;
		

		if(f > k) break;
		if(f >=0 && nums[f]) {
			res.first = f; 
			res.second = k;
		} 
		i--;
	}
}


int main (int argc, char const* argv[]) {
	int n, k;
	while(scanf("%d", &n) > 0){
		mst(nums, 0);
		v.clear();
		fr(i, 0, n){
			sc1(k); 
			if(!nums[k]) v.pb(k);
			nums[k]=1;
		}
		sc1(p);
		go();
		printf("Peter should buy books whose prices are %d and %d.\n", res.first, res.second);
		_
	}	
	return 0;
}
