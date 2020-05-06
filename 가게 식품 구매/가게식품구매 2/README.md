
1.장어덮밥(5000원) 2.옥수수콘(10000원) 3.감자튀김(3000원) 4.총 가격

선택할 번호 : 1

몇번째 손님이 1번 장어덮밥을 선택하셨습니다. 누적금이 얼마입니다

선택할 번호 : 4

감사합니다. 총 가격은 5000원입니다.

계속 구매하시겠다면 1번, 아니면 2번을 눌러주세요.

선택할 번호 : 1

계속 진행합니다.




```c
#include <stdio.h>

int main() {
	int customer_num = 0;
	int rice = 5000;
	int corn = 10000;
	int fries = 3000;
	int sum = 0;
	int sum_add = 0;
	int select_num = 1;

	char menu_rice[9] = "장어덮밥";
	char menu_corn[9] = "옥수수콘";
	char menu_fries[9] = "감자튀김";

	int 인원;

	printf("\n몇 명일까요? : ");
	scanf("%d", &인원);

	printf("\n1. %s (%d)  2. %s (%d)  3. %s (%d) 4. 총 가격\n", menu_rice, rice, menu_corn, corn, menu_fries, fries);
	for (customer_num = 1; customer_num <= 인원;) {
		printf("당신은 %d번째 손님입니다. 메뉴를 선택하세요.\n", customer_num);
		printf("번호를 선택하세요:");
		scanf("%d", &select_num);
		if (select_num == 1) {
			sum += rice;
			printf("\n%d번째 손님이 %d번 %s를 선택하셨습니다. \n누적금은 %d원입니다.\n\n", customer_num, select_num, menu_rice, sum);
		}
		else if (select_num == 2) {
			sum += corn;
			printf("\n%d번째 손님이 %d번 %s를 선택하셨습니다. \n누적금은 %d원입니다.\n\n", customer_num, select_num, menu_corn, sum);

		}
		else if (select_num == 3) {
			sum += fries;
			printf("\n%d번째 손님이 %d번 %s를 선택하셨습니다. \n누적금은 %d원입니다.\n\n", customer_num, select_num, menu_fries, sum);

		}
		else if (select_num == 4) {
			printf("감사합니다. 총 가격은 %d원입니다.\n\n", sum);
			printf("계속 구매하시겠다면 1번, 아니면 2번을 눌러주세요.\n번호를 입력하세요:");
			scanf("%d", &select_num);
			if (select_num == 1) {
				printf("\n계속 진행합니다.\n\n");
			}
			else if (select_num == 2) {
				printf("\n%d번째 손님의 메뉴선택을 종료합니다.\n총 누적금은 %d원입니다.\n\n\n", customer_num, sum);
				break;
			}
		}
}
```
