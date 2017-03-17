#include<bits/stdc++.h>
#define NMAX 1000
#define pb push_back
using namespace std;

struct edge{
	int s,d,wt;
};
vector<edge> adj;
vector<int> dis(NMAX);

void addEdge(int u,int v,int w){
	edge e;
	e.s = u;
	e.d = v;
	e.wt = w;
	adj.pb(e);
}

void bellmanFordAlgo(int n, int m, int src){
	//Initialization of all vertices except source to infinity
	for(int i = 0;i < n;i++){
		dis[i] = INT_MAX;
	}
	int u,v,w;
	dis[src] = 0;
	
	//Shortest path from src to every other vertex
	for(int i = 1;i < n;i++){
		for(int j = 0;j < m;j++){
			u = adj[j].s;
			v = adj[j].d;
			w = adj[j].wt;
			if(dis[u] != INT_MAX && dis[v] > dis[u]+w){
				dis[v] = dis[u]+w;
			}
		}
	}
	
	//Negative cycle check
	for(int i = 0;i < m;i++){
		u = adj[i].s;
		v = adj[i].d;
		w = adj[i].wt;
		if(dis[u] != INT_MAX && dis[v] > dis[u]+w){
				cout<<"Negative Weight Cycle";
				break;
			}
	}
}

void solution(){
	adj.clear();
	int n,m,u,v,w,src;
	
	ifstream in;
	char filename[10000];
	//cout<<"\nEnter the name of the file\n";
	//Enter the name of the input file to use (.txt)
	//gets(filename);
	//in.open(filename);
	in.open("5V8E.txt");
	in>>n>>m;
	//File format
	for(int i = 0;i < m;i++){
		in>>u>>v>>w;
		addEdge(u-1,v-1,w);
	}
	bellmanFordAlgo(n,m,src);
	
	cout<<"Source vertex: "<<src<<"\n";
	cout<<"Vertex distance from src "<<"\n";
	for(int i = 0;i < n;i++){
		cout<<i<<" \t "<<dis[i]<<"\n";
	}
}



int main(){
	clock_t startTime = clock();	
	solution();	//To read from file.txt
	double exeTime = double( clock() - startTime ) / (double)CLOCKS_PER_SEC;
	cout<<"\n"<<exeTime<<" seconds."<<"\n";
	return 0;
}
