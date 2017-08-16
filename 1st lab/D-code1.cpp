#include<cstdio>
#define INF 0x80000000	//int�����ܱ�ʾ����С����
//����a�洢�����Ĺ�Ʊ�۸����飬����b�洢��Ʊ�۸�仯����
int a[1000010],b[1000010];
//�˺������ڷ��η�����������������
int max_sub_array(int arr[],int l,int r)
{
	if(l<r){
        int mid=(l+r)/2;
        int suml=max_sub_array(arr,l,mid);	//���������������������
        int sumr=max_sub_array(arr,mid+1,r);	//���ұ�����������������
        int sum_both=0;

		//Ѱ����벿�����������
        int max_left=INF;
        for(int i=mid;i>=l;i--)
        {
            sum_both+=arr[i];
            if(sum_both>max_left)
                max_left=sum_both;
        }

		//Ѱ���Ұ벿�����������
        int max_right=INF;
        sum_both=0;
        for(int i=mid+1;i<=r;i++)
        {
            sum_both+=arr[i];
            if(sum_both>max_right)
                max_right=sum_both;
        }
		
		//�����Խ�е������������
        sum_both=max_left+max_right;

		//�ж�����������������õ����������
		if(sumr<sum_both && suml<sum_both)
			return sum_both;
        else if(suml<sumr)
        	return sumr;
        else
        	return suml; 
}
    else 
        return arr[l];	//����l==r������
}

int main()
{
	int n,t;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(i>0) b[i]=a[i]-a[i-1];	//����õ��۸�仯����
		}
		int sum = max_sub_array(b,1,n-1);
		if(sum<=0) printf("No solution\n");
		else printf("%d\n",sum);
	}
}
