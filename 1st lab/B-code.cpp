#include <cstdio>
int main() {
    int n;
    while(~scanf("%d", &n)) {
        int ans = 0;
        while(n) {
            n >>= 1;	//�˴���n/=2�����ͬ����λ����Ч�ʸ���
            ans++;
        }
        printf("%d\n", ans);
    }
}