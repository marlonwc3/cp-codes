#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
	
struct Node {
	Node *next;
	int val;
	Node(int _val){val = _val; next = NULL;}
};

struct List{
	Node *head;
	Node *tail;
	Node *index;
	int size;
	List(){
		head = tail = index =NULL;
		size=0;}

	void push_back(int val){
		Node *aux = new Node(val);
		if(head==NULL) head = tail = index = aux;
		else{
			tail->next = aux;
			tail = aux;
		}
		size++;
	}

	int acess(){
		int val = index->val;
		index = index->next;
		if(index == NULL) index = head;
		return val;
	}
};

List adjList[105];


bool mark[105];

void dfs(int ini, int father){
	mark[ini] = 1;
	int s = adjList[ini].size;
	for(int i = 0; i < s; i++){
		int adj = adjList[ini].acess();
		if(adj != father && !mark[adj]) dfs(adj, ini);
	}
}



int main(int argc, char const *argv[]) {
	int t = 0;
	int e, l, a, b;
	while(true){
		scanf("%d %d", &e, &l);
		if(e==l && e==0) break;
		t++; // testcase
		memset(adjList,0,sizeof adjList);
		memset(mark, 0, sizeof mark);
		for(int i = 0 ; i < l; i++){
			scanf("%d %d", &a, &b);
			adjList[a].push_back(b);
			adjList[b].push_back(a);
		}

		dfs(1,0);
		bool ok = true;
		for (int i = 1; i <= e; ++i) if(!mark[i]) {ok = false; break;}
		printf("Teste %d\n", t);
		if(!ok) printf("falha");
		else printf("normal");
		printf("\n\n");
	}
	return 0;
}

