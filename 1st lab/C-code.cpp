#include<cstdio>
int buf[1000010];		//������洢ǰi������
int a[1000010];			//������洢�������ݣ��ɲ���Ҫ
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
		//������߽�������Ԥ����
        for(int l=1;l<=n;l++){
            scanf("%d",&a[l]);
            //����Ԥ�������
            if(l==1) buf[l]=a[l];
            else buf[l]=buf[l-1]^a[l];
        }
        int t;
        scanf("%d",&t);
        while(t--){
            int i,j;
            scanf("%d%d",&i,&j);
            MySwap(i,j);	//��Ŀ��i, j��С��ȷ���������Ҫ��������
            if(i==j) printf("%d\n",a[i]);
            else{
                int ans=buf[i-1]^buf[j];		//������
                printf("%d\n",ans);
            }
        }
	}
}
int main()
{
	buf[0]=0;	//ע�������ѯ��һ����Ϊ1��Ҫ����������в���
	run();
}
