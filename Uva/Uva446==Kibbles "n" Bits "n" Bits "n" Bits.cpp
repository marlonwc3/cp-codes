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
 
int toDecimal(string a){
        int len = a.length(), sum =0;
        fr(i,0,len){
                sum*=16;
                sum += ( a[i]>='0' && a[i] <= '9' ) ? (a[i]-'0') : (a[i]-'A' + 10);
        }
        return sum;
}
 
string toBin(int k){
        string res = k ? "" :  "0", aux;
        while(k){
                aux = (k%2)+'0';
                res = aux + res;
                k/=2;
        }
        while( res.length() < 13) {
                res = "0" + res;
        }
 
        return res;
}
 
char str1[50], str2[50], str3[50];
int main(int argc, char const *argv[]) {
        int t, a,b;
        string s1, s2, s3;
        sc1(t);
        while(t--){
                scanf("%s %s %s", str1, str2, str3);
                a = toDecimal(str1);
                b = toDecimal(str3);
                //printf("str1: %s | str3: %s | A: %d | B: %d\n", str1, str3, a, b);
                s1 = toBin(a);
                s2 = toBin(b);
                if(str2[0]=='+') a+=b;
                else a-=b;
                printf("%s %s %s = %d\n", s1.c_str(), str2, s2.c_str(), a);
 
        }
 
        return 0;
}
