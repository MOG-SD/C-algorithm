#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

const int inf = INT_MAX; 

void Dijkstra(int n,int source,int *dist,int *prev,int c[5][5])
{
	//接下来先进行初始化操作
	bool s[n];//用于表示点是否在s集合里 
	for(int i=0; i<n; i++){
		dist[i] = c[source][i];
		//初始化的时候，除了source外所有的点都不在 s集合 
		s[i] = i == source ? true : false;
        //结点暂时不可达，前驱结点记作-1
		//此时结点可达，表示与源结点相邻，前驱点是源点
		prev[i] = dist[i] == inf ? -1 : source; 
	} 

	for(int i=1; i<n; i++)//没有用到i的值，只是控制循环次数,表示要找n-1个点 
	{
		int minDist = inf;
		int newNode;//u记录下距离source最近的点
		
		for(int j=0; j<n; j++){	//从v-s集合中找点 
			//j点不在s集合中，且到source的距离小于上一个点到source的距离，就用u记录下该点 
			if(!s[j] && dist[j]<minDist){
				newNode = j;
				minDist = dist[newNode];
			}
		}
		
		s[newNode] = true;//将u点加入s集合
		
		for(int j=0; j<n; j++){//当s集合加入新点的时候需要更新dist[]和prev[] 
			if(!s[j] && c[newNode][j]<inf){//j点不在s集合中，且 新点与 j点相邻 
				int newDist = dist[newNode] + c[newNode][j];//新点到source的距离 + 新点到 j点的距离
				if( newDist < dist[j] ){
				    dist[j] = newDist;
					prev[j] = newNode;//新点成了j的前驱点，表示此时从source到j点经过u距离最短 
				}
			}
		} 
	} 
}

int main()
{
	/*
	n个点
	dist[i]表示从source点到 i点的最短距离
	k=previous[i]表示经过 k点到达 i点才是最短路径 
	c[][]是临接矩阵 
	*/ 
	
	int c[5][5]={
					{0,10,inf,30,100},
					{inf,0,50,inf,inf},
					{inf,inf,0,inf,10},
					{inf,inf,20,0,60},
					{inf,inf,inf,inf,0}
				};
	int n = 5;
	int dist[n];
	int prev[n];
	int source = 0;
	
	Dijkstra(n,source,dist,prev,c);	
	cout<<"源点到各点的最短距离为：";
	for(int i=0; i<n; i++){
		cout<<dist[i]<<" ";
	}
	return 0;
}


