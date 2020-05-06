[문제]
- 처음에 개인정보들을 입력받는다 > 나이, 성별, 전화번호, 주민번호, 카드비밀번호
- 처음 주민번호를 입력할 때 6자리를 입력받게 하고, 만약 6자리가 안 된다면 기회를 3번 주고, 그래도 틀리다면 프로그램을 종료.
- 만약 입력된 주민번호가 일치하다면, 카드 번호 4자리를 입력할 수 있게 하라. 이 역시 4자리가 되지 않는다면 기회를 3번 주고 프로그램을 종료.
- 그 후 1.계좌 조회. 2.계좌 입금 3.계좌 출금이 가능하도록 설정하여라. 단, 처음에 2번과 3번을 입력할 시 [처음에는 계좌 조회만 가능합니다.]라는 문구가 나타남.
- 1번을 입력할 경우 계좌에 얼마가 들어있는지 나오게 하고, 그 상황에서 다시 첫 번째 상황으로 이동.
- 첫 번째 상황으로 이동했다면 1번을 누를 시 [계좌 조회는 1회만 가능합니다]가 나타나도록 하고, 2, 3번만 입력할 수 있음.
- 2번을 입력 시 금액을 입금할 수 있음
- 3번을 누를 시 계좌에서 돈을 뺄 수 있게 하고, 가지고 있는 돈보다 많이 출금하려 할 시 [잔액이 부족합니다.] 라는 문구가 뜸.
- 절대 계좌 내에서 –라는 금액이 보이면 안 됨



```c
#include <stdio.h>

int main() {
	int age = 0;
	char s;
	int id = 0;
	int wrong = 0;
	int phone = 0;
	int card_p = 0;
	int aa;
	int bb;
	int select = 0;
	int card_i = 0;
	int sum = 0;
	int money = 0;


	printf("나이를 입력하세요 : ");
	scanf("%d", &age);
	printf("성별을 입력하세요 : ");
	getchar();
	scanf("%c", &s);
	printf("전화번호를 입력하세요 : ");
	getchar();
	scanf("%d", &phone);
aa:
	if (wrong != 0) {
		printf("주민번호는 6자리여야 합니다.\n다시 입력하세요 : ");
	}
	else if (wrong == 0) {
		printf("주민번호 6자리를 입력하세요 : ");
	}
	scanf("%d", &id);
	if (id<100000 || id>999999) {
		wrong++;

		if (wrong != 3) {

			goto aa;
		}
		else if (wrong == 3) {
			break;
		}
	}
	else {
		wrong = 0;
	}
bb:
	if (wrong != 0) {
		printf("카드비밀번호는 4자리여야 합니다.\n다시 입력하세요 : ");
	}
	else if (wrong == 0) {
		printf("카드 비밀번호 4자리를 입력하세요 : ");
	}
	scanf("%d", &card_p);
	if (card_p<1000 || card_p>9999) {
		wrong++;
		if (wrong != 3) {
			goto bb;
		}
		else if (wrong == 3) {
			return 0;
		}
	}
	else {
		wrong = 0;


		while (1) {
			printf("1. 계좌 조회   2. 계좌 입금  3. 계좌 출금 ");
			printf("\n\n번호를 선택하세요 : ");
			scanf("%d", &select);
			if (select == 1) {
				if (card_i == 1) {
					printf("\n\n계좌 조회는 1회만 가능합니다.\n 2,3번만 가능합니다.\n\n");
				}
				else {
					printf("\n\n현재 계좌에는 %d원이 있습니다.\n\n", sum);
					card_i++;
				}

			}
			else if (select == 2) {
				if (card_i == 0) {
					printf("\n\n처음에는 계좌 조회만 가능합니다.\n\n");

				}
				else {
					printf("\n계좌에는 총 %d원 있습니다.\n\n", sum);
					printf("\n\n입금 하실 금액을 입력하세요 : ");
					scanf("%d", &money);
					sum += money;
					printf("\n계좌에는 총 %d원 있습니다.\n\n", sum);
				}

			}
			else if (select == 3) {
				if (card_i == 0) {
					printf("\n\n처음에는 계좌 조회만 가능합니다.\n\n");
				}
				else {
					printf("\n\n출금하실 금액을 입력하세요 : ");
					scanf("%d", &money);
					if ((sum - money) < 0) {
						printf("\n잔액이 부족합니다.\n\n");
					}
					else {
						sum -= money;
						printf("\n\n계좌에는 총 %d원이 남았습니다.\n\n", sum);
					}
				}
			}
		}
	}

}

```
