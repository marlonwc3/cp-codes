#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define nd second
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
 
vi sieve;
bool mark[32790];
void gosieve(){
        mark[0]=mark[1]=1;
        fr(i,0,32790){
                if(mark[i])continue;
                sieve.pb(i);
                for(ll j = ll(i)*i; j<32790 && j > 0 ; j+=i) mark[j]=1;
        }
}
 
stack<ii> pf;
void getPf(int n){
        pf = stack<ii>();
        int id=0, f = sieve[0];
        while(n!=1 && f*f <= n) {
                int k = 0;
                while( n%f == 0 ){
                        n/=f; k++;
                }
                if(k) pf.push(mp(f, k));
                id++; f = sieve[id];
        }
        if(n!=1) {
                pf.push(mp(n,1));
        }
}
 
int fexp(int a, int b){
        if(!b) return 1;
        if(b==1) return a;
        int r = fexp(a, b/2); r*=r;
        if(b%2 == 1) r *=a;
        return r;
}
 
char line[50000];
int main(int argc, char const *argv[]) {
        gosieve();
        int sum = 0, p, e;
        bool b = 0;
        while(1){
                gets(line);
                if(line[0]=='0' && strlen(line)==1)break;
                sum = 1;
                char *pch = strtok(line, " ");
                while( pch  != NULL ) {
                        if(!b) sscanf(pch, "%d", &p);
                        else {
                                sscanf(pch, "%d", &e);
                                sum *= fexp(p, e);
                        }
                        b=!b;
                        pch = strtok(NULL, " ");       
                }
                sum--;
                getPf(sum);
                printf("%d %d", pf.top().st, pf.top().nd );  pf.pop();
                while(!pf.empty()){
                        printf(" %d %d", pf.top().st, pf.top().nd );  pf.pop();
                }
                _
        }
 
 
 
 
        return 0;
}
