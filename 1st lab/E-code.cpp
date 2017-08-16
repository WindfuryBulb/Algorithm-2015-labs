#include<cstring>
#include<iostream>
using namespace std;
int a[10010],b[10010],c[10010];
//c存储原数组，a将原数组复制之后存储排序结果，b为辅助数组

//归并排序算法
long long slot(int head, int tail)
{
	long long ans=0;
    if(head>=tail)	//需要处理这样的情形
        return 0;
    int mid=(head+tail)/2;
	int i=head,j=mid+1,k=i;
	//统计左右两个子数组的逆序数并进行子数组的排序
	ans=slot(head,mid)+slot(mid+1,tail);

	//合并子数组过程
	//操作过程中累加逆序对的数量
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

	//必要的补充
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
			//复制数组操作
			for(int i=0;i<n;i++)
				a[i]=c[i];
        	long long ans=slot(x,y);
        	cout<<ans<<endl;
		}
    }
}
