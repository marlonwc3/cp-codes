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
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
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
typedef pair<char, int> ci;


int arr[3];

int main (int argc, char const* argv[]) {
	while(1){
		fr(i,0,3) sc1(arr[i]);
		if(!arr[0] && !arr[1] && !arr[2]) break;
		if(arr[0]!=arr[1] && arr[0]!=arr[2] && arr[1] != arr[2]) {
			arr[0]=1; arr[1] = 1; arr[2] = 2;
		}
		else if(arr[0]==arr[1] && arr[0]==arr[2] && arr[1] == arr[2]) { // 3 igual
			arr[0]++; arr[1] = arr[0]; arr[2] = arr[0]; 
			if(arr[0] > 13 ) {printf("*\n"); continue;}
		}	
		else {
			sort(arr, arr + 3);
			int k = (arr[1]==arr[0]) ?  2 : 0; 
			arr[k]++;
			if(arr[k]>13) {
				arr[0]=1; arr[1]++; arr[2] = arr[1];
			}
			else {
				if(arr[0] == arr[1] && arr[1] == arr[2] ){
					arr[k]++;
					if(arr[k] > 13 ) {
						arr[0] =1 ; arr[1]++; arr[2]++;
						if(arr[1] > 13 ) {arr[1] =arr[2] = 1;}
					}	
				}
				
			}
			
			
		}
		sort(arr, arr + 3);
		printf("%d %d %d\n", arr[0], arr[1], arr[2]);
		
		
	}
	
	
	return 0;
}


