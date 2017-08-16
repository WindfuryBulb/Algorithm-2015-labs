#include <cstdio>
int main() {
    int n;
    while(~scanf("%d", &n)) {
        int ans = 0;
        while(n) {
            n >>= 1;	//此处与n/=2意义等同，但位运算效率更高
            ans++;
        }
        printf("%d\n", ans);
    }
}