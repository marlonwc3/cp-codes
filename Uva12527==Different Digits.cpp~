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
typedef set<ii> sii;
typedef set<int> si;
typedef pair<char, int> ci;


bool is(int k){
    int mark[15];
    mst(mark, 0);
    while(k){
        mark[k%10]++;
        if(mark[k%10] >= 2 ) return 0;
        k/=10;
    }
    return 1;
}



int freq[5050];

int get(int a, int b){
    return freq[b] - freq[a-1];
}

int main (int argc, char const* argv[]) {
    freq[0] = 1;
    fe(i,1,5040){
        
        freq[i] = is(i);
        freq[i] += freq[i-1];
       // printf("i: %d | %d | freq %d \n", i, is(i) , freq[i] );
        
    }
    int a, b;
    while( sc2(a,b) ==2 ){
        printf("%d\n", get(a, b) );
    
    }
    
    
    
    
    return 0;
}







