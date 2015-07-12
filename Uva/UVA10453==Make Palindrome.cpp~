#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <deque>
#include <queue>
#include <functional>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <string>
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

#define addEdge(a,b) to[z] = b; ant[z] = adj[a]; adj[a] = z++
#define addEdgeC(a,b,c) from[z] = a; to[z] = b; ant[z] = adj[a]; adj[a] = z; cost[z] = c; z++
#define rp(a,b) fr(a,0,b)
#define MP make_pair
#define F first
#define S second
const int infinity = 0x3f3f3f3f;
const long long longInfinity = 0x3f3f3f3f3f3f3f3fLL;
typedef pair<int,int> pii;
typedef pair<pii,int> trii;
typedef long long ll;
typedef priority_queue<pii, vector<pii>, greater<pii> > HeapPii;

typedef long long ll;
typedef pair<int, int> ii;


typedef pair<int, string> is;
string str;
int pd_ok[1005][1005], PASSO;
int pd[1005][1005];
ii pai[1005][1005];



int go(int i, int j){
    if(i>=j){ if(i==j){pai[i][j] = mp(-1,-1); } return 0;  }
    if(pd_ok[i][j] == PASSO ) { return pd[i][j]; }
    int r;
 //   printf("i: %d | j: %d | str: %s \n", i, j, str.c_str() );
    if(str[i]==str[j]){
        r = go(i+1, j-1);
        pai[i][j] = mp(i+1, j-1);
    }
    else{
        r = go(i+1, j);
        pai[i][j] = mp(i+1,j);
        int r2 = go(i, j-1);
        if(r2 < r){
            r = r2;
            pai[i][j] = mp(i, j-1);
        }
        r++;
    }

    pd_ok[i][j] = PASSO;
    pd[i][j] = r;
    return r;
}

string path(int i,int j){
    string aux, aux2;
    if(i > j || i < 0 || j < 0 ) return "";
      aux = str[i], aux2 = str[j] ;
    if(i==j) {

        return aux;
    }
    
    int pi = pai[i][j].st, pj = pai[i][j].nd;
    if( pi == i+1 && pj == j-1 ){
        return aux + path(pi, pj) + aux2;
    }
    if(pi == i+1 && pj == j ) {
        return aux + path(pi, pj) + aux;
    }
    return aux2 + path(pi, pj) + aux2;
    
}



int main (int argc, char const* argv[]){
    int r;
    PASSO = 0;
    string s;
    while(getline(cin, str)){
        PASSO++;
//        printf("STR: %s\n", str.c_str() );
        r = go(0, str.length() -1 ); 
        s = path(0, str.length() -1 );
         
        printf("%d %s\n", r, s.c_str() );      

    
    }
    
    
    
    
    return 0;
}

















