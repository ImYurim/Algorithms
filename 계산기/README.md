- goto 문 이용

- 처음에는 두 숫자를 모두 입력받음.

- 예시 )
  첫 번째 숫자 : 10
	기호 : +
	두 번째 숫자 : 30

	+ - x / 

  10 + 30 = 40

- 이후에는 두 번째 숫자만 입력받는데, 두 번째 숫자로 30을 입력받게 되면,
	이전에 더해졌던 숫자가 나타남.
	40 + 30 = 70

- 그리고 숫자 0을 누르지 않는 이상, 계속해서 반복할 수 있게 함



```c
#include <stdio.h>
int main() {
	int n1 = 0;
	int n2 = 0;
	int r = 0;
	char cal;
	int aa;
	int n = 0;

	while (1) {

		printf("첫 번째 숫자를 입력하세요: ");
		scanf("%d", &n1);

		if (n1 == 0) {
			break;
		}

	aa:
		printf("\n\n\n+, -, x, / 중 기호를 입력하세요 : ");
		getchar();
		scanf("%c", &cal);

		if (n2 == 0) {
			printf("\n\n두 번째 숫자를 입력하세요: ");

		}
		else {
			printf("\n\n숫자를 입력하세요 : ");
			n = 1;
		}
		scanf("%d", &n2);

		if (n2 == 0) {
			break;
		}

		if (n == 1) {
			n1 = r;
		}

		if (cal == '+') {
			r = n1 + n2;
			printf("%d + %d = %d", n1, n2, r);
			goto aa;
		}
		else if (cal == '-') {
			r = n1 - n2;
			printf("%d - %d = %d", n1, n2, r);
			goto aa;
		}
		else if (cal == 'x') {
			r = n1 * n2;
			printf("%d x %d = %d", n1, n2, r);
			goto aa;
		}
		else if (cal == '/') {
			r = n1 / n2;
			printf("%d / %d = %d", n1, n2, r);
			goto aa;
		}

	}
}


```
