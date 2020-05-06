입력할 수 있는 n의 변수가 존재한다.
f의 기본값은 1이며, n의 변수만큼 증가하며 출력한다.
f가 출력한 숫자 중에 짝수의 합은 얼마인가 ?

n : 10
	1
	2
	3
	4
	5
	6
	7
	8
	9
	10

	짝수의 합 : 30

```c
#include <stdio.h>

int main() {


		int n = 0;
	int f = 1;
	int sum_e = 0;

	printf("n의 값을 입력하세요:");
	scanf("%d", &n);

	for (; f <= n; f++) {
		printf("%d\n", f);
		if (f % 2 == 0) {
			sum_e = sum_e + f;
		}
	}

	printf("\n\n짝수의 합 : %d", sum_e);


}

```
