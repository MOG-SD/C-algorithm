#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<bitset>
#include<string>
using namespace std;

//【不要4 62】
//给定一个闭区间[l,r],问这个区间内有多少个满足题意的数（不能出现4和62）; 
typedef long long ll;
int a[20];
int dp[20][2];
int dfs(int pos,int pre,int sta,bool limit)
{
    if(pos==-1) return 1;
    if(!limit && dp[pos][sta]!=-1) return dp[pos][sta];
    int up=limit ? a[pos] : 9;
    int tmp=0;
    for(int i=0;i<=up;i++)
    {
        if(pre==6 && i==2)continue;
        if(i==4) continue;//都是保证枚举合法性
        tmp+=dfs(pos-1,i,i==6,limit && i==a[pos]);
    }
    if(!limit) dp[pos][sta]=tmp;
    return tmp;
}
int solve(int x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,-1,0,true);
}
int main()
{
    int le,ri;
    //memset(dp,-1,sizeof dp);可优化
    while(~scanf("%d%d",&le,&ri) && le+ri)
    {
        memset(dp,-1,sizeof dp);
        printf("%d\n",solve(ri)-solve(le-1));
    }
    return 0;
}

/*
判断闭区间[l,r]之间有多少数满足题意（即各位数的和可以被10整除）
long long a[1000],dp[1000][10];
int n;


long long dfs(int pos,int prefix,int sum,bool limit){
	sum = sum%10;
	if(pos == -1){
		if(sum == 0)	return 1;
		else 			return 0;
	}
	if(!limit&&dp[pos][sum]!=-1)	return dp[pos][sum];
	int up = limit?a[pos]:9;
	int temp = 0;
	for(int i=0;i<=up;i++){
		temp += dfs(pos-1,i,sum+i,limit&&i==a[pos]);
	}
	if(!limit)	dp[pos][sum] = temp;
	return temp;
}

long long solve(int x){
	int pos=0;
	while(x){
		a[pos++] = x%10;
		x/=10;
	}
	return dfs(pos-1,-1,0,true);
}
*/

