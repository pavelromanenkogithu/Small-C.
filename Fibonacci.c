#include <stdio.h>

int main() {
    int i, n;
    int ar[20];

    printf("Enter number (1 to 20): ");
    scanf("%d", &n);

    ar[0] = 1;
    ar[1] = 1;

    printf("%d %d", ar[0], ar[1]);

    for (i = 2; i <= n; i++) {
        ar[i] = ar[i-1] + ar[i-2];
        printf(", %d", ar[i]);
    }

    return 0;
}
