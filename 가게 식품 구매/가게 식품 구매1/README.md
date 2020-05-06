- 몇 번째 사람인지, 합이 얼만지, 해당 음식은 몇 개 째인지 늘 나타내기.
- 껌은 5통 초과로 구매하려 하면, 5개 초과로 구매할 수 없다는 말과 함께 다시 구매하게 하기
- 4번 종료를 눌렀을 경우, 2번 과자가 10의 배수가 아니라면, 현재 과자가 몇 개니, 다시 구매해야 한다는 문장과 함께 다시 구매할 수 있게 하기
- 4번 종료를 눌렀을 경우, 3번 복숭아가 과자보다 적다면, 복숭아가 더 적을 수 없다는 문장과 함께 다시 선택할 수 있게 하기
- 만약 위 문제 없이 정상적으로 4번 종료가 처리되었다면 아래 문장을 나타내기

--오늘의 매출--
껌 x 5개 : 25000원

오늘의 매출 : 25000원

- 위처럼, 아예 구매하지 않은 제품에 한해서는 나타내지 않기
- do while 사용

-기본 메뉴
[1.껌-5000원 2.과자7000원 3.복숭아-4000 4.종료]




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
