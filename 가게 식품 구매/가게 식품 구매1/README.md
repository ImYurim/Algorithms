```c
#include <stdio.h>

int main() {

	int people = 1;
	int sum;
	int n;
	int gum_s = 0;
	int snack_s = 0;
	int peach_s = 0;

	while (1) {
		printf("당신은 %d번째 손님입니다.\n\n", people);
		do {
			printf("[1.껌-5000원    2.과자-7000원     3.복숭아-4000원      4.종료]\n");
			printf("구매하실 제품의 번호를 입력하세요:");
			scanf("%d", &n);

			if (n == 1) {

				printf("\n현재까지 산 껌의 개수는 %d개 입니다.\n", gum_s);
				gum_s++;
				if (gum_s > 5) {
					printf("껌은 5개 초과로 구매할 수 없습니다.\n", gum_s);
					gum_s--;
					printf("\n다른 제품을 구매해주세요.\n\n");
				}
				else if (gum_s <= 5) {
					printf("껌을 총 %d개 구매하였습니다.\n\n\n", gum_s);
				}

			}
			else if (n == 2) {
				printf("\n현재까지 산 과자의 개수는 %d개 입니다.\n", snack_s);
				snack_s++;
				printf("과자를 총 %d개 구매하였습니다.\n\n\n", snack_s);
			}
			else if (n == 3) {
				printf("\n현재까지 산 복숭아의 개수는 %d개 입니다.\n", peach_s);
				peach_s++;
				printf("복숭아를 총 %d개 구매하였습니다.\n\n\n", peach_s);

			}
			else if (n == 4) {
				if (snack_s % 10 != 0 || (peach_s < snack_s)) {
					if (snack_s % 10 != 0) {
						printf("\n현재 과자의 개수는 %d개 이고 10배수가 아니므로 다시 구매하세요.\n\n", snack_s);
					}
					if (peach_s < snack_s)
					{
						printf("\n현재 복숭아의 개수는 %d개 이고 과자의 개수는 %d개 입니다. \n복숭아의 개수가 과자의 개수보다 적을 수 없습니다.\n", peach_s, snack_s);
						printf("다시 구매하세요.\n\n");
					}
				}

				else {
					printf("\n\n==========오늘의 매출==========\n\n");
					if (gum_s > 0) {
						printf("껌 x %d개  :  %d원\n", gum_s, gum_s * 5000);
					}
					if (snack_s > 0) {
						printf("과자 x %d개  :  %d원\n", snack_s, snack_s * 7000);
					}
					if (peach_s > 0) {
						printf("복숭아 x %d개  :  %d원\n", peach_s, peach_s * 4000);
					}
					sum = gum_s * 5000 + snack_s * 7000 + peach_s * 4000;
					printf("오늘의 매출 : %d원\n\n\n", sum);
					people++;
					gum_s = 0;
					snack_s = 0;
					peach_s = 0;
				}
			}
		} while (n != 4 && snack_s % 10 != 0 || (peach_s < snack_s));
	}
}
```
