#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
#include<deque>
#include<map>
#include<cmath>
#include<stack>
#include<set>
#include<vector>
#include<algorithm>
#define endl '\n';
#define MAX 0x3f3f3f3f;
using namespace std;

int n,m;

//默认是从点1出发 
int solve(int road[][2001]){
	//这里的source代表的含义是：例如source[3]=5,从5出发到3 
	int source[n+1],lowdist[n+1],sum;
	//f用于判断点是否已经被连接起来了 
	bool f[n+1] ={false};
	for(int i=1;i<=n;i++){
		source[i] = 1;
		lowdist[i] = road[1][i];
	}
	f[1] = true;
	for(int i=0;i<n-1;i++){//这里的i只用于计数，要进行n-1个循环,无其他用途 
		int newnode;
		int mindist = MAX;
		for(int i=1;i<=n;i++){
			if(lowdist[i] < mindist&&!f[i]){
				mindist = lowdist[i];
				newnode = i;
			}
		}
		sum += mindist;
		f[newnode] = true;
		//newnode被连接进来后,更新一下新的lowdist,并且也更新一下新的lowdist的source 
		for(int i=1;i<=n;i++){
			if(!f[i]&&road[newnode][i]<lowdist[i]){
				lowdist[i] = road[newnode][i];
				source[i] = newnode;
			}
		} 
	}
	return sum; 
}
	
int main(){
	cin>>n>>m;
	int road[n+1][2001];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			road[i][j] = MAX;
		}
	}
	for(int i=0;i<m;i++){
		int a,b,dist;
		cin>>a>>b>>dist;
		road[a][b] = dist;
		road[b][a] = dist;
	}
	cout<<solve(road);
}


