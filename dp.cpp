#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long a[15][15];
long long dp[15][1<<12];
int n,m;
bool judge1(int s){//�жϵı�׼�Ǳ�����������Ϊ1 
	int i;
	for(i=0;i<m;){
		if(s & (1<<i)){
			if(i==m-1)return 0;
			else if(s & (1<<(i+1)))i+=2;
			else return 0;
		}
		else i++;
	}
	return 1;
}
bool judge2(int s,int ss){//�жϵ�i-1�е�s�����i�е�����Ƿ���� 
	int i;
	for(i=0;i<m;){
		if(s & (1<<i)){
			if(ss & (1<<i)){ 
				if(i==m-1 ||!(s &(1<<i+1))||!(ss &(1<<i+1)))return 0;
				else i+=2;
			}
			else i++;
		}
		else{
			if(ss &(1<<i))i++;
			else return 0;
		}
	}
	return 1;
}
void solve(){
	int s,ss,i;
	memset(dp,0,sizeof(dp));
	if(n<m){//Ϊ�˼������������ʹС��Ϊ���� 
		int temp;
		temp=n;n=m;m=temp;
	}
	int maxx=(1<<m)-1;
	for(s=0;s<=maxx;s++){//��һ��ÿһ�ֿ��е���� 
		if(judge1(s)){ 
			dp[1][s]=1;
		}
	}
	for(i=2;i<=n;i++){
		for(s=0;s<=maxx;s++){
			for(ss=0;ss<=maxx;ss++){
				if(judge2(s,ss)){//�жϵ�i-1�����i������Ƿ���� 
					dp[i][ss]+=dp[i-1][s];
				}
			}
		}
	}
	a[n][m]=a[m][n]=dp[n][maxx];
	cout<<a[n][m]<<endl;
}
int main(){
	int i,j;
	memset(a,-1,sizeof(a));
	while(scanf("%d%d",&n,&m)!=EOF&&n&&m){
		if(a[n][m]!=-1){//��Ϊ-1������Լ��ó��� 
			cout<<a[n][m]<<endl;
			continue;
		}
		if(n&1 && m&1){//������Ϳ�Ϊ�������򷽰���Ϊ0 
			a[n][m]=a[m][n]=0;
			cout<<a[n][m]<<endl;
			continue;
		}
		solve();
	}
	return 0;
}
