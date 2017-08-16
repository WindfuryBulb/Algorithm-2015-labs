#include<cstdio>
int buf[1000010];		//此数组存储前i项异或和
int a[1000010];			//此数组存储输入数据，可不需要
void MySwap(int &i, int &j){
	if(i>j){
		int temp=j;
		j=i;
		i=temp;
	}
}
void run(){
	int n;
	while(~scanf("%d",&n)){
		//边输入边进行数据预处理
        for(int l=1;l<=n;l++){
            scanf("%d",&a[l]);
            //数据预处理过程
            if(l==1) buf[l]=a[l];
            else buf[l]=buf[l-1]^a[l];
        }
        int t;
        scanf("%d",&t);
        while(t--){
            int i,j;
            scanf("%d%d",&i,&j);
            MySwap(i,j);	//题目中i, j大小不确定，因此需要交换操作
            if(i==j) printf("%d\n",a[i]);
            else{
                int ans=buf[i-1]^buf[j];		//计算结果
                printf("%d\n",ans);
            }
        }
	}
}
int main()
{
	buf[0]=0;	//注意如果查询有一个数为1需要对这个数进行操作
	run();
}
