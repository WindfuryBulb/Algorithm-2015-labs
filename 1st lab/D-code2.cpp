#include<cstdio>
int main(){
	int n;
	while(~scanf("%d",&n)){
		int res,ans=0,x;		//ans��¼���ս����res��¼����a[n]ǰi-1�����Сֵ
		int inp1=scanf("%d",&x);
		res=x;
		for(int i=2;i<=n;i++){
			scanf("%d",&x);	//x�൱�ڼ�¼a[i]�ĵ�ǰֵ
			//���������������ļ������
			if(ans<x-res)
				ans=x-res;

			//��������ǰi-1����Сֵ�ļ������
			if(x<res)
				res=x;
		}
		if(ans==0) printf("No solution\n");
		else printf("%d\n",ans);
	}
}
