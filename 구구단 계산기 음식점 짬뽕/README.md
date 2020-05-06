```c
#include <stdio.h>

int main() {
	int n1;
	int n2;
	int n2_n;
	int n2_1 = 3000;
	int n2_2 = 4000;
	int n2_3;
	int n2_3_1 = 5000;
	int n2_3_2 = 6000;
	int n2_3_3 = 7000;
	int n2_sum = 0;
	int n3;
	int n3_1;
	int n3_2;
	int n3_a = -1;
	int n3_r = 0;

	while (1) {
		printf("[1.구구단 2.음식점 3.계산기 4.종료]\n번호를 입력하세요:");
		scanf("%d", &n1);
		/*
		1. 2단만 나오는 구구단을 설정해주세요.
		1-1 : 2단이 지속적으로 출력된다. 2x1 ~ 2x9
		1-2 : 구구단 2단이 끝나면 다시 처음 메뉴[1.구구단 2.음식점 3.계산기 4.종료]로 다시 빠져나간다.
		1-3 : 거기서 다시 1번을 누르면 또다시 구구단 2단이 나타난다.*/

		if (n1 == 1) {
			int i = 1;
			while (i < 10) {
				printf("2x%d\n", i);
				i++;
			}
			printf("\n\n");
		}
		/*
		2. 음식점을 차릴 건데, 포스기에서 사용하는 코딩을 설정해주세요. [1.볶음밥 2.자장면 3.탕수육[소`중`대 따로] 4.종료] 금액 본인이 설정.


		*/
		else if (n1 == 2) {
			while (1) {
				printf("\n\n[1.볶음밥 %d원 2.자장면 %d원 3.탕수육[소-%d원`중- %d원`대-%d 따로] 4.종료].\n번호를 입력하세요:", n2_1, n2_2, n2_3_1, n2_3_2, n2_3_3);
				scanf("%d", &n2);
				if (n2 == 1) {
					n2_sum = n2_sum + n2_1;
					printf("\n\n볶음밥 %d원이 추가되었습니다.\n", n2_1);
					printf("\n누적금액은 %d원입니다.\n", n2_sum);
				}
				else if (n2 == 2) {
					n2_sum = n2_sum + n2_2;
					printf("\n\n자장면 %d원이 추가되었습니다.\n", n2_2);
					printf("\n누적금액은 %d원입니다.\n", n2_sum);
				}
				else if (n2 == 3) {
					while (1) {
						printf("\n\n1.소[5000원] 2.중[6000원] 3.대[7000원] 4. 이전메뉴\n번호를 입력하세요:");
						scanf("%d", &n2_3);
						if (n2_3 == 1) {
							n2_sum = n2_sum + n2_3_1;
							printf("\n\n1.소\n탕수육 소 %d원이 추가되었습니다.\n", n2_3_1);
							printf("\n\n누적금액은 %d원입니다.\n", n2_sum);
						}
						else if (n2_3 == 2) {
							n2_sum = n2_sum + n2_3_2;
							printf("\n\n1.중\n탕수육 중 %d원이 추가되었습니다..\n", n2_3_2);
							printf("\n\n누적금액은 %d원입니다.\n", n2_sum);

						}
						else if (n2_3 == 3) {
							n2_sum = n2_sum + n2_3_3;
							printf("\n\n1.대\n탕수육 대 %d원이 추가되었습니다..\n", n2_3_3);
							printf("\n\n누적금액은 %d원입니다.\n", n2_sum);

						}
						else if (n2_3 == 4) {
							printf("\n\n누적금액은 %d원입니다.\n", n2_sum);
							break;
						}
					}
				}
				else if (n2 == 4) {
					printf("\n\n");
					break;
				}
			}
		}
		/*
		3. 계산기가 필요해요. 더하기와 빼기만 있으면 되는데 가능할까요?
		*/
		else if (n1 == 3) {
			printf("\n\n계산기가 필요해요. 더하기와 빼기만 있으면 되는데 가능할까요?\n");
			printf("1. 더하기 2. 빼기\n\n번호를 입력하세요:");
			scanf("%d", &n3);

			if (n3 == 1 && n3_a == -1) {
				printf("\n첫 번째 숫자를 입력하세요:");
				scanf("%d", &n3_1);
				printf("\n두 번째 숫자를 입력하세요:");
				scanf("%d", &n3_2);
				n3_a = n3_1 + n3_2;
				printf("%d + %d = %d\n", n3_1, n3_2, n3_a);
			}
			else if (n3 == 1 && n3_a != -1) {
				printf("\n두 번째 숫자를 입력하세요:");
				scanf("%d", &n3_2);
				printf("%d + %d = ", n3_1, n3_2);
				n3_a = n3_a + n3_2;
				printf("%d\n", n3_a);
			}
			if (n3 == 2 && n3_a == -1) {
				printf("\n첫 번째 숫자를 입력하세요:");
				scanf("%d", &n3_1);
				printf("\n두 번째 숫자를 입력하세요:");
				scanf("%d", &n3_2);
				while (n3_1 < n3_2) {
					printf("두 번째 숫자가 첫 번째 숫자보다 클 수 없습니다. 다시 입력하세요\n");
					printf("\n두 번째 숫자를 입력하세요:");
					scanf("%d", &n3_2);
				}
				n3_a = n3_1 - n3_2;
				printf("%d - %d = %d\n", n3_1, n3_2, n3_a);
			}
			else if (n3 == 2 && n3_a != -1) {
				printf("\n두 번째 숫자를 입력하세요:");
				scanf("%d", &n3_2);
				while (n3_a < n3_2) {
					printf("두 번째 숫자가 첫 번째 숫자보다 클 수 없습니다. 다시 입력하세요\n");
					printf("\n두 번째 숫자를 입력하세요:");
					scanf("%d", &n3_2);
				}
				printf("%d - %d = ", n3_a, n3_2);
				n3_a = n3_a - n3_2;
				printf("%d\n", n3_a);
			}
		}
		/*
		4. 종료
		중국집에서 나온 금액 + 계산기에서 마지막으로 나타난 금액
		*/
		else if (n1 == 4) {
			printf("중국집에서 나온 금액 %d원 + 계산기에서 나온 금액 %d = %d", n2_sum, n3_a, n2_sum + n3_a);
			return 0;
		}
	}
}


```
