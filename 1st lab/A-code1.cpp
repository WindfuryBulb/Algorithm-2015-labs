#include<iostream>
#include<cstdio>
using namespace std;
#define MO 1000007
long long bufx[10010];
int main()
{
	int n,x,t;
	int ans;
	int cnt = 1;
	bufx[0]=1;
	while(cin>>n>>x>>t){
		cout<<"Case #"<<cnt<<":\n";
		cnt++;
		//下述代码对x的n次幂进行存储操作，即数据预处理
		for(int i=1;i<=n;i++)
			bufx[i]=((bufx[i-1]%MO)*(x%MO)+MO)%MO;
		while(t--){
			ans=0;		//注意各次查询前对答案初始化
			for(int i=0;i<=n;i++){
				int buf;
				cin>>buf;
				//下述代码计算各项的值并进行加法操作
				ans+=((buf%MO)*(bufx[i]%MO)+MO)%MO;
				ans%=MO;
			}
			cout<<ans<<endl;
		}
	}
}