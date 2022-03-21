#include<bits/stdc++.h>
using namespace std;

int n,q;
long long a[100001],c[100001],sum1[100001],sum2[100001];

int lowbit(int x){
	return x&-x;
}
/*
//求x的前缀和 (区间查询)
long long getsum(int x){
    long long ans = 0;
    for(;x;x -= lowbit(x))	ans += c[x];
    return ans;
}

//单点更新 
void update(int x,int y){
    for(;x<=n;x += lowbit(x))    //x为更新的位置,y为增加的量,n为数组最大值
        c[x] += y;
}
*/

//区间更新 和 区间查询 

long long getsum(int x){
	int res = 0,temp = x;
	for(;x;x-=lowbit(x)){
		res += sum1[x]*temp - sum2[x];
	}
	return res;
}

void update(int x,int y){
	int temp = x;
	for(;x<=n;x += lowbit(x)){
		sum1[x] += y;
		sum2[x] += y*(temp - 1);
	}
}

int main(){
	int l,r;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		update(i,a[i]-a[i-1]);
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		cout<<getsum(r)-getsum(l-1)<<endl;
	}
	return 0;
}

