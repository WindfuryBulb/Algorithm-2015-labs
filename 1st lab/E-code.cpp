#include<cstring>
#include<iostream>
using namespace std;
int a[10010],b[10010],c[10010];
//c�洢ԭ���飬a��ԭ���鸴��֮��洢��������bΪ��������

//�鲢�����㷨
long long slot(int head, int tail)
{
	long long ans=0;
    if(head>=tail)	//��Ҫ��������������
        return 0;
    int mid=(head+tail)/2;
	int i=head,j=mid+1,k=i;
	//ͳ����������������������������������������
	ans=slot(head,mid)+slot(mid+1,tail);

	//�ϲ����������
	//�����������ۼ�����Ե�����
    while((i<=mid) && (j<=tail))
    {
        if(a[i]<=a[j])
        {
            b[k++]=a[i++];
            ans+=(j-mid-1);
        }
        else
            b[k++]=a[j++];
	}

	//��Ҫ�Ĳ���
    while(i<=mid)
    {
        b[k++]=a[i++];
        ans+=(j-mid-1);
    }
    while(j<=tail)
        b[k++]=a[j++];
    for(i=head; i<=tail; ++i)
        a[i]=b[i];
    return ans;
}
int main()
{
    int n,t,x,y;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
            cin>>c[i];
		cin>>t;
		while(t--){
			cin>>x>>y;
			memset(b,0,sizeof(b));
			//�����������
			for(int i=0;i<n;i++)
				a[i]=c[i];
        	long long ans=slot(x,y);
        	cout<<ans<<endl;
		}
    }
}
