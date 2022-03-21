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
	//�������Ƚ��г�ʼ������
	bool s[n];//���ڱ�ʾ���Ƿ���s������ 
	for(int i=0; i<n; i++){
		dist[i] = c[source][i];
		//��ʼ����ʱ�򣬳���source�����еĵ㶼���� s���� 
		s[i] = i == source ? true : false;
        //�����ʱ���ɴǰ��������-1
		//��ʱ���ɴ��ʾ��Դ������ڣ�ǰ������Դ��
		prev[i] = dist[i] == inf ? -1 : source; 
	} 

	for(int i=1; i<n; i++)//û���õ�i��ֵ��ֻ�ǿ���ѭ������,��ʾҪ��n-1���� 
	{
		int minDist = inf;
		int newNode;//u��¼�¾���source����ĵ�
		
		for(int j=0; j<n; j++){	//��v-s�������ҵ� 
			//j�㲻��s�����У��ҵ�source�ľ���С����һ���㵽source�ľ��룬����u��¼�¸õ� 
			if(!s[j] && dist[j]<minDist){
				newNode = j;
				minDist = dist[newNode];
			}
		}
		
		s[newNode] = true;//��u�����s����
		
		for(int j=0; j<n; j++){//��s���ϼ����µ��ʱ����Ҫ����dist[]��prev[] 
			if(!s[j] && c[newNode][j]<inf){//j�㲻��s�����У��� �µ��� j������ 
				int newDist = dist[newNode] + c[newNode][j];//�µ㵽source�ľ��� + �µ㵽 j��ľ���
				if( newDist < dist[j] ){
				    dist[j] = newDist;
					prev[j] = newNode;//�µ����j��ǰ���㣬��ʾ��ʱ��source��j�㾭��u������� 
				}
			}
		} 
	} 
}

int main()
{
	/*
	n����
	dist[i]��ʾ��source�㵽 i�����̾���
	k=previous[i]��ʾ���� k�㵽�� i��������·�� 
	c[][]���ٽӾ��� 
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
	cout<<"Դ�㵽�������̾���Ϊ��";
	for(int i=0; i<n; i++){
		cout<<dist[i]<<" ";
	}
	return 0;
}


