#include <bits/stdc++.h>
 
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define pb(a) push_back(a)
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a), __ = (b) ; i < __; i++)
#define fe(i,a,b) for(int i=(a), __ = (b); i<= __ ; i++)



using namespace std;
typedef vector<int> vi;
 
const int MAX_WORDS = 1000, MAX_ALPHA = 26*2;
const int MAX_N= 1000*1000;

inline int get(char c){
	if(c>='a')	return c-'a';
	 return c-'A'+26;
}
 
struct Node{
    int adj[MAX_ALPHA + 5], fail;
    bitset<MAX_WORDS> words;
    Node(){ memset(adj, -1, sizeof adj); words.reset(); fail = 0; }
    int& operator[](int i){return adj[i]; }
};
Node tree[MAX_N+5];
const int ROOT =0;
int next_word, next_node;
inline void init(){ 
	tree[ROOT] = Node(); next_word = 0;  next_node = 1;
}
 
void add(const string &w){
    int at = ROOT;
    char ch;
    fr(i,0,w.length() ){
       ch = get(w[i]);
       if(tree[at][ch]==-1) { 
       	tree[next_node++] = Node(); 
        tree[at][ch] = next_node - 1;
       }
       at = tree[at][ch];
    }
    tree[at].words[next_word++] = 1;
}
 
void build_fail(){
    queue<int> q;
    fr(i,0,MAX_ALPHA){
        if(tree[ROOT][i] != -1 ) {
            q.push(tree[ROOT][i]);
        }
    }
    int at, adj, fail;
    while(!q.empty()){
        at = q.front(); q.pop();
        fr(i,0,MAX_ALPHA){
            adj = tree[at][i];
            if(adj == -1 ) continue;    
            fail = tree[at].fail;
            while(fail != ROOT && tree[fail][i] == -1 ) fail = tree[fail].fail;
            if(tree[fail][i] != -1 ) fail = tree[fail][i];
            tree[adj].fail = fail; 
            tree[adj].words |= tree[fail].words;
            q.push(adj);
        }
    }
}
 
void build_trie(const vector<string> &words){
    init();
    fr(i,0,words.size()) add(words[i]);
    build_fail(); 
}
 

 
bitset<MAX_WORDS> search(const string &text) {
    int at = ROOT;
    char ch;
    bitset<MAX_WORDS> ans;
    fr(i,0,text.length()){
        ch = get(text[i]);
        while(at != ROOT && tree[at][ch] == -1 ) at = tree[at].fail;
        if(tree[at][ch] != -1 ) at = tree[at][ch];
        ans |= tree[at].words;
    }
    return ans;
}
 
void print_result(const vector<string> &words, const bitset<MAX_WORDS> &result ) {
    fr(i,0,MAX_WORDS){
        if(result[i]){
            printf("Found: %s\n", words[i].c_str() );
        }
    }
}
 
string line;
vector<string> words;
string text;
 
int main (int argc, char const* argv[]){
	int caso, N;
	sc1(caso); getline(cin, line);
	bitset<MAX_WORDS> ans;
	while(caso--){
		getline(cin,text);
		words.clear();
		sc1(N); getline(cin, line);
		fr(i,0,N){
			getline(cin,line);
			words.pb(line);
		}
		build_trie(words);
		ans = search(text);
		fr(i,0,N){
			puts(ans[i]?"y":"n");
		}
	}	
    return 0;
}














