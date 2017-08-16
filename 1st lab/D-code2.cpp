#include<cstdio>
int main(){
	int n;
	while(~scanf("%d",&n)){
		int res,ans=0,x;		//ans记录最终结果，res记录数组a[n]前i-1项的最小值
		int inp1=scanf("%d",&x);
		res=x;
		for(int i=2;i<=n;i++){
			scanf("%d",&x);	//x相当于记录a[i]的当前值
			//迭代计算最大收益的计算过程
			if(ans<x-res)
				ans=x-res;

			//迭代计算前i-1项最小值的计算过程
			if(x<res)
				res=x;
		}
		if(ans==0) printf("No solution\n");
		else printf("%d\n",ans);
	}
}
