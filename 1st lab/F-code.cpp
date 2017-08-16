#include<iostream>
using namespace std;

const int SUM = 6;	//�˴�6ԭ��Ϊ1+2+3


long long slot(int p[], int i, int res)
{
    if(i==0) return 0;
    else if(p[i]==res) return slot(p,i-1,res);
    else{
        int other = SUM - p[i] - res;
        long long buf = 1LL<<(i-1);
        return slot(p,i-1,other)+buf;
    }
}

int main()
{
    int n;
    int st[65],ed[65];
    while(cin>>n){
        if(n==0) break;
        for(int i=1;i<=n;i++) cin>>st[i];
        for(int i=1;i<=n;i++) cin>>ed[i];

        long long ans = 0;
        int k = n;
		//Ѱ������һ����Ҫ�ƶ�������
        while(st[k]==ed[k]&&k>0) k--;
        if(k>0){
            int other = SUM - st[k] - ed[k];	/*���k�����ӳ���ʼ����ֹ�������
													�Ǹ���������*/
            ans = slot(st,k-1,other)+slot(ed,k-1,other)+1;
        }
        else ans=0;
        cout<<ans<<endl;
    }   
}
