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

int reg[15];
int ram[1100];

int getlast(int k){
    return k%10;
}
int getmid(int k){
    k%=100;
    return k/10;
}
const int MOD = 1000;

int main(int argc, char const *argv[]) {
    int t, id = 0, k, s, d;
    string line;
    sc1(t); 
    getline(cin, line);
    getline(cin,line);
    bool first = 1;
    while(t--){
        if(!first) _
        mst(reg, 0);
        mst(ram, 0);
        id = 0;
        while(getline(cin, line) && !line.empty() ){
            sscanf(line.c_str() , "%d", &ram[id++]);
        }
        int cnt = 0;
        int i = 0;
        while( i<1000 ) { 
            k = ram[i];
            cnt++;
            if( k == 100 ) break;
            d = getmid(k);
            s = getlast(k);
            if( k <= 99){
                if(reg[s]){ i = (reg[d]-1)%MOD; }
            }
            else if (k <= 299){
                reg[d]=(s%MOD);
            }
            else if (k <= 399){
                reg[d]= (reg[d]+s)%MOD;
            }
            else if (k <= 499){ 
                reg[d] = (reg[d]*s)%MOD;
            }
            else if (k <= 599){
                reg[d] = reg[s]%MOD;
            }
            else if (k <= 699){
                reg[d] = (reg[d]+reg[s])%MOD;
            }
            else if (k <= 799){
                reg[d] = (reg[d]*reg[s])%MOD;
            }              
            else if (k <= 899){
                reg[d] = ram[reg[s]]%MOD;
            }              
            else if (k <= 999){
                ram[reg[s]] = reg[d]%MOD;
            }   
            i++;                                                                     
        }
        printf("%d\n", cnt);
        first =  0;
    }

    return 0;
}