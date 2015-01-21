#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
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
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;
 
int coins[11] = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5 };
ll mem[11][30005];
ll bt(int p , int sum){
        if( sum < 0  ) return 0;
        if(!sum) { return 1; }
        if( p >= 11 ) return 0;
        if(coins[p] > sum ) return 0;
        if(mem[p][sum]!=-1 )return mem[p][sum];
        ll i  = 0;
        ll r = 0;
        while( i*coins[p] <= sum ) {
                r += bt(p+1,  sum -  i*coins[p] );
                i++;
        }
        return mem[p][sum] = r;
}
 
int parse(string s){
        int len =  s.length(), p; p = len;
        fr(i,0,len) { if(s[i]=='.') {p = i; break; } }
        int sum  = 0, sum2 = 0;
        fr(i,0,p) sum = (s[i]-'0') + 10*sum;
        fr(i,p+1, len) sum2 = (s[i]-'0') + 10*sum2;
        if( len - (p+1) == 1 ) sum2*=10;
        return sum*100 + sum2;
}
 
int main(int argc, char const *argv[]) {
 
        mst(mem, -1);
        sort(coins, coins+11);
        string line;
        int n;
        while(getline(cin, line) ){
                n = parse(line); iz(n);
                ll res  = bt(0, n);
                printf("%6s%17lld\n", line.c_str(), res);
        }
        return 0;
}
