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



char str[100], str2[100];


char matrix[100][50];
int mcont[50];

char find(char ch, int row){
    char k;
    fr(j,0,27){
        if(matrix[row][j] == ch ) {
            if( j == 26) return ' ';
            return j+'a';
        }
    }
    
}


int main (int argc, char const* argv[]) {
     bool num = 0;
   // printf("%d %d", 'a'-'a', 'z'-'a');
    scanf("%s", str);

    char ch;
    int qt = 0;
    for(int i  =0; str[i]; i++){
        if(num){
            mcont[qt] = str[i]-'0';
            qt++;
        }
        else{
            if(str[i]==':') {qt = 0; num=1; continue;}
            ch = str[i];
            fr(j,0,27){
               matrix[qt][j] = ch;
               // printf("%c ", ch);
               if(ch  ==' ') ch = 'A';
               else{  
                   ch++;
                   if(ch > 'Z'){ ch = ' '; }
               }
            }
           // _
            qt++;
        }
    }

    // fr(i,0,qt) printf("%d\n", mcont[i] );
    string line;
    getline(cin,line);
    while(getline(cin,line)){
        //printf("LISE: %s\n", line.c_str() );
        int len = line.length();
        int cnt = 0, row = 0;
        fr(i,0,len){
            line[i] = find(line[i], row);
            cnt++;
            if( cnt>= mcont[row]) {
                cnt = 0;
                row = (row+1)%qt;
            }
        }
        printf("%s\n", line.c_str() );
        
    }
    
    
    
    return 0;
}













