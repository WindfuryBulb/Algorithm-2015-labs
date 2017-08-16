#include<cstdio>
#define INF 0x80000000	//int类型能表示的最小负数
//数组a存储给出的股票价格数组，数组b存储股票价格变化数组
int a[1000010],b[1000010];
//此函数用于分治法求解最大子数组问题
int max_sub_array(int arr[],int l,int r)
{
	if(l<r){
        int mid=(l+r)/2;
        int suml=max_sub_array(arr,l,mid);	//求左边子数组的最大子数组
        int sumr=max_sub_array(arr,mid+1,r);	//求右边子数组的最大子数组
        int sum_both=0;

		//寻找左半部分数组的最大和
        int max_left=INF;
        for(int i=mid;i>=l;i--)
        {
            sum_both+=arr[i];
            if(sum_both>max_left)
                max_left=sum_both;
        }

		//寻找右半部分数组的最大和
        int max_right=INF;
        sum_both=0;
        for(int i=mid+1;i<=r;i++)
        {
            sum_both+=arr[i];
            if(sum_both>max_right)
                max_right=sum_both;
        }
		
		//计算跨越中点子数组的最大和
        sum_both=max_left+max_right;

		//判断三种情况哪种情况求得的子数组最大
		if(sumr<sum_both && suml<sum_both)
			return sum_both;
        else if(suml<sumr)
        	return sumr;
        else
        	return suml; 
}
    else 
        return arr[l];	//处理l==r的情形
}

int main()
{
	int n,t;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(i>0) b[i]=a[i]-a[i-1];	//处理得到价格变化数组
		}
		int sum = max_sub_array(b,1,n-1);
		if(sum<=0) printf("No solution\n");
		else printf("%d\n",sum);
	}
}
