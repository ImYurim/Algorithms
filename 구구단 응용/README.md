```c
#include <stdio.h>

int main(){
  int mul_n = 0;
	int mul_n2 = 0;
	int mul_n_10 = 0;
	int r;

	for (mul_n = 2; mul_n <= 40; mul_n++) {
		if (mul_n % 2 == 0) {


			if (mul_n == 4 || mul_n == 8 || mul_n == 14) {
			}
			else if (mul_n == 18 || mul_n == 20) {
				if (mul_n == 18) {
					mul_n2 = 118;
					printf("============구구단 %d단============", mul_n);
					mul_n++;
				}
				else {
					mul_n2 = 220;
					printf("============구구단 %d단============", mul_n);
					mul_n++;
					mul_n_10 = 1;
					
				}
				for (int i = 1; i <= 9; i++) {
					r = 0;
					r = mul_n2 * i;
					printf("\n%d x %d = %d\n", mul_n2, i, r);
				}

			}
			else if ((mul_n2 != 0) || (mul_n % 10 == 0)) {
				mul_n++;
				mul_n_10 = 1;
			}
			else {
				printf("============구구단 %d단============", mul_n);
				for (int i = 1; i <= 9; i++) {
					r = 0;
					r = mul_n * i;
					printf("\n%d x %d = %d\n", mul_n, i, r);
				}
			}



		}
		if (mul_n_10 == 1) {
			printf("============구구단 %d단============", mul_n);
			for (int i = 1; i <= 9; i++) {
				r = 0;
				r = mul_n * i;
				printf("\n%d x %d = %d\n", mul_n, i, r);
			}
			mul_n_10 = 0;
			mul_n2 = 0;
		}


	}
}
```
