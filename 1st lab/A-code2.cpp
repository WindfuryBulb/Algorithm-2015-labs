#include<iostream>
#include<cstdio>
using namespace std;
#define MO 1000007
long long buf[10010];	//buf�������ڴ洢ϵ��
long long gans[10010];	//gans�������ڴ洢���β�ѯ�ļ�����
int main()
{
	int n,t;
	long long x;
	long long ans;
	int cnt = 1;
	while(cin>>n>>x>>t){
		for(int j=0;j<t;j++){
            ans=0;
            for(int i=0;i<=n;i++)
                cin>>buf[i];
            //�������������ؾ����㷨����һԪn�ζ���ʽ��ֵ
            ans+=buf[n];
            for(int i=n-1;i>=0;i--){
                ans*=x;
                ans+=MO;
                ans%=MO;
                ans+=buf[i];
                ans%=MO;
            }
            gans[j]=ans;
		}
		printf("Case #%d:\n",cnt++);
		for(int i=0;i<t;i++)
            cout<<gans[i]<<endl;
	}
}
