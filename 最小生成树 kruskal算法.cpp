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
#define endl '\n';
#define sup 1<<30;
using namespace std;

int root[200001];
int n,m;

class roat{
public:
	int a;
	int b;
	int dist;
};

bool cmp(roat a,roat b){
	return a.dist<b.dist;
}

int find(int x){
	int temp = x; 
	while(root[x] != x){
		x = root[x];
	}
	root[temp] = x;
	return root[temp];
}

void connect(int a,int b){
	if(find(a) == find(b)){
		
	}else{
		root[find(a)] = b;
	}
}


long long solve(roat* r){
	long long sum = 0;
	for(int i=1;i<=n;i++){
		root[i] = i;
	}
	for(int i=0;i<m;i++){
		int a = r[i].a,b = r[i].b;
		if(find(a) == find(b)){
			continue;
		}else{
			connect(a,b);
			sum += r[i].dist;
		}					
	}
	return sum;
}

int main(){
	cin>>n>>m;
	roat r[m];
	for(int i=0;i<m;i++){
		cin>>r[i].a>>r[i].b>>r[i].dist;
	}
	sort(r,r+m,cmp);
	cout<<solve(r);
}



