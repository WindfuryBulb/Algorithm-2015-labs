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
		//���������x��n���ݽ��д洢������������Ԥ����
		for(int i=1;i<=n;i++)
			bufx[i]=((bufx[i-1]%MO)*(x%MO)+MO)%MO;
		while(t--){
			ans=0;		//ע����β�ѯǰ�Դ𰸳�ʼ��
			for(int i=0;i<=n;i++){
				int buf;
				cin>>buf;
				//���������������ֵ�����мӷ�����
				ans+=((buf%MO)*(bufx[i]%MO)+MO)%MO;
				ans%=MO;
			}
			cout<<ans<<endl;
		}
	}
}