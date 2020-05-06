
#include <stdio.h>

int main{}{
int num_f = 0; //입력숫자
	int num_s = 0; //입력숫자 총 합
	int num_r = 0;  //맞추기 전 최근 숫자
	int rule = 0; //맞추기 전 적용된 규칙
	int give_hint_p1 = 0;
	int give_hint_p2 = 0;
	char p1[5];
	char p2[5];
	int n1 = 0;
	int n2 = 0;
	int turn_p1 = 0;
	int break_p1 = 0;
	int break_p1_n = 0;
	int turn_p2 = 0;
	int break_p2 = 0;
	int break_p2_n = 0;

	printf("지금부터 게임을 진행합니다.\n\n\n");
	printf("입력은 100이상 1000이하여야 하고, 5의 배수만 허용합니다.\n\n\n");
	printf("첫번째 번호 입력 : ");
	scanf("%d", &num_f);
	num_s = num_s + num_f;
	printf("두번째 번호 입력 : ");
	scanf("%d", &num_f);
	num_s = num_s + num_f;
	printf("세번째 번호 입력 : ");
	scanf("%d", &num_f);
	num_s = num_s + num_f;
	printf("네번째 번호 입력 : ");
	scanf("%d", &num_f);
	num_s = num_s + num_f;
	printf("\n\n\n번호 저장 완료.\n\n");
	printf("자, 숫자는 제공되었고, 이제는 입력된 숫자가 모두 더해졌습니다.\n\n우리는 그 답을 맞춰보도록 하겠습니다. 최대한 빠른 사람이 승리입니다.\n\n");

	printf("1번 플레이어의 이름을 입력하여 주십시오 : ");
	scanf("%s", &p1);
	printf("\n\n\n2번 플레이어의 이름을 입력하여 주십시오 : ");
	scanf("%s", &p2);

	printf("\n\n\n%s님, %s님 반갑습니다.\n\n\n", p1, p2);
	printf("지금부터 게임을 진행할 것인데, 몇 가지 소소한 규칙을 정하도록 하겠습니다.\n\n\n");
	printf("규칙 1 : 입력할 숫자는 100이상 1000이하여야 하고, 5의 배수이다.\n\n");
	printf("규칙 2 : 7의 배수 번째에[둘 다 끝나야 1턴종료] 답을 맞춘 경우 정답이 +- 150이 되며, 이는 플레이어에게 알리지 않는다.\n- 단, 이전에 쓴 답이 크다면 - 시키고, 이전에 쓴 답이 작다면 + 시킨다.\n\n");
	printf("규칙 3 : 규칙 2번이 실행된 상태에서 바로 다음 턴에 정답을 맞출 경우, 일정한 숫자로 답이 변화하고, 해당 규칙에 걸린 사람에게만 다음 턴에 힌트가 부여된다.\n\n");
	printf("규칙 4 : 규칙 1을 어긴사람은 턴을 상대방에게 뺏기게 된다.\n\n");
	printf("규칙 5 : 10번째 턴까지 온 경우,  규칙에 의해 숫자가 변했었다면 변하기 전 숫자와 숨은 규칙을 알려준다.\n\n");


	printf("최대한 빨리 정확한 숫자를 찾아내는 것이 중요하며 각각 총 10번의 기회가 주어지는데 그 안에 못 찾을 시 무승부로 끝난다.\n\n\n");


	printf("==========컴퓨터가 알려주는 지원===========\n\n");
	printf("플레이어가 제시한 숫자보다 크거나 작을 시 컴퓨터가 알려줍니다. 그럼 게임을 시작하겠습니다.\n\n");
	printf("\n\n%s님부터 시작합니다.\n\n", p1);

	do {
		
	
		
		if (break_p2 == 1) {
			do {
				if (turn_p1 == 9 && turn_p2 == 9 && rule != 0) {
					if (rule == 2) {
						printf("바로 이전에 적용된 규칙은 규칙 %d입니다. 이 규칙은 이전 답에 +150 혹은 -150을 했습니다. ", rule);
					}
					if (rule == 3) {
						printf("바로 이전에 적용된 규칙은 규칙 %d입니다. 이 규칙은 이전 답에 +10을 했습니다.", rule);
					}
				}
				if (give_hint_p1 == 1) {
					printf("규칙 3이 적용되기 이전에 정답을 맞추셨으니 힌트를 드립니다.\n\n");

					printf("정답은 100으로 나눌 경우 나머지가 %d입니다.", num_s % 100);
				}

				//첫번째 플레이어
				printf("%s님이 입력할 숫자 : ", p1);
				scanf("%d", &n1);
				if ((n1 > 100) && (n1 < 1000) && (n1 % 5 == 0)) {  //첫번째 규칙
					turn_p2++;
					if (num_s > n1) {

						printf("%s님이 입력하신 숫자보다 답이 더 큽니다.\n\n", p1);

					}
					else if (num_s < n1) {
						printf("%s님이 입력하신 숫자보다 답이 더 작습니다.\n\n", p1);
					}
					else {
						if (turn_p1 == 6 && turn_p2 == 6) {
							if (num_r < num_s) {
								num_s = num_s + 150;
							}
							else {
								num_s = num_s - 150;
							}
							rule = 2;
						}
						else if (turn_p1 == 6 && turn_p2 == 6 && rule == 2) {
							num_s = num_s + 10;
							give_hint_p1 = 1;
							rule = 3;
						}
						else {
							printf("정답입니다!!!!\n\n");
							break;
						}
					}
					num_r = n1;
					break_p2 = 0;
					break_p2_n--;
				}
				else {
					printf("규칙을 어겼습니다. 상대에게 턴을 뺏깁니다.\n\n");
					break_p1 = 1;
					break_p1_n = 2;
				}
			} while (break_p2_n != 0);

		}
		else {
			if (turn_p1 == 9 && turn_p2 == 9 && rule != 0) {
				if (rule == 2) {
					printf("바로 이전에 적용된 규칙은 규칙 %d입니다. 이 규칙은 이전 답에 +150 혹은 -150을 했습니다. ", rule);
				}
				if (rule == 3) {
					printf("바로 이전에 적용된 규칙은 규칙 %d입니다. 이 규칙은 이전 답에 +10을 했습니다.", rule);
				}
			}
			if (give_hint_p1 == 1) {
				printf("규칙 3이 적용되기 이전에 정답을 맞추셨으니 힌트를 드립니다.\n\n");

				printf("정답은 100으로 나눌 경우 나머지가 %d입니다.", num_s % 100);
			}
			printf("%s님이 입력할 숫자 : ", p1);
			scanf("%d", &n1);
			if ((n1 > 100) && (n1 < 1000) && (n1 % 5 == 0)) {  //첫번째 규칙
				turn_p1++;
				if (num_s > n1) {

					printf("%s님이 입력하신 숫자보다 답이 더 큽니다.\n\n", p1);

				}
				else if (num_s<n1) {
					printf("%s님이 입력하신 숫자보다 답이 더 작습니다.\n\n", p1);
				}
				else {
					if (turn_p1 == 6 && turn_p2 == 6) {
						if (num_r < num_s) {
							num_s = num_s + 150;
						}
						else {
							num_s = num_s - 150;
						}
						rule = 2;

					}
					else if (turn_p1 == 6 && turn_p2 == 6 && rule == 2) {
						num_s = num_s + 10;
						give_hint_p1 = 1;
						rule = 3;
					}
					else {
						printf("정답입니다!!!!\n\n");
						break;
					}
				}
				num_r = n1;
			}
			else {
				printf("규칙을 어겼습니다. 상대에게 턴을 뺏깁니다.\n\n");
				break_p1 = 1;
				break_p1_n = 2;
			}

		}


		//두번째 플레이어 
		if (break_p1 == 1) {
			do {
				if (turn_p1 == 9 && turn_p2 == 9 && rule != 0) {
					if (rule == 2) {
						printf("바로 이전에 적용된 규칙은 규칙 %d입니다. 이 규칙은 이전 답에 +150 혹은 -150을 했습니다. ", rule);
					}
					if (rule == 3) {
						printf("바로 이전에 적용된 규칙은 규칙 %d입니다. 이 규칙은 이전 답에 +10을 했습니다.", rule);
					}
				}
				if (give_hint_p2 == 1) {
					printf("규칙 3이 적용되기 이전에 정답을 맞추셨으니 힌트를 드립니다.\n\n");

					printf("정답은 100으로 나눌 경우 나머지가 %d입니다.", num_s % 100);
				}
				printf("%s님이 입력할 숫자 : ", p2);
				scanf("%d", &n2);
				if ((n2 > 100) && (n2 < 1000) && (n2 % 5 == 0)) {
					turn_p1++;
					if (num_s > n2) {

						printf("%s님이 입력하신 숫자보다 답이 더 큽니다.\n\n", p2);

					}
					else if (num_s < n2) {
						printf("%s님이 입력하신 숫자보다 답이 더 작습니다.\n\n", p2);
					}
					else {
						if (turn_p1 == 6 && turn_p2 == 6) {
							if (num_r < num_s) {
								num_s = num_s + 150;
							}
							else {
								num_s = num_s - 150;
							}
							rule = 2;
						}
						else if (turn_p1 == 6 && turn_p2 == 6 && rule == 2) {
							num_s = num_s + 10;
							give_hint_p2 = 1;
							rule = 3;
						}
						else {
							printf("정답입니다!!!!\n\n");
							break;
						}
					}
					break_p1 = 0;
					num_r = n2;
					break_p1_n--;

				}
				else {
					printf("규칙을 어겼습니다. 상대에게 턴을 뺏깁니다.\n\n");
					break_p2 = 1;
					break_p2_n = 2;
				}
			} while (break_p1_n != 0);
		}


		else {
			if (turn_p1 == 9 && turn_p2 == 9 && rule != 0) {
				if (rule == 2) {
					printf("바로 이전에 적용된 규칙은 규칙 %d입니다. 이 규칙은 이전 답에 +150 혹은 -150을 했습니다. ", rule);
				}
				if (rule == 3) {
					printf("바로 이전에 적용된 규칙은 규칙 %d입니다. 이 규칙은 이전 답에 +10을 했습니다.", rule);
				}
			}
			if (give_hint_p2 == 1) {
				printf("규칙 3이 적용되기 이전에 정답을 맞추셨으니 힌트를 드립니다.\n\n");

				printf("정답은 100으로 나눌 경우 나머지가 %d입니다.", num_s % 100);
			}
			printf("%s님이 입력할 숫자 : ", p2);
			scanf("%d", &n2);
			if ((n2 > 100) && (n2 < 1000) && (n2 % 5 == 0)) {
				turn_p2++;
				if (num_s > n2) {

					printf("%s님이 입력하신 숫자보다 답이 더 큽니다.\n\n", p2);

				}
				else if (num_s<n2) {
					printf("%s님이 입력하신 숫자보다 답이 더 작습니다.\n\n", p2);
				}
				else {
					if (turn_p1 == 6 && turn_p2 == 6) {
						if (num_r < num_s) {
							num_s = num_s + 150;
						}
						else {
							num_s = num_s - 150;
						}
						rule = 2;
					}
					else if (turn_p1 == 6 && turn_p2 == 6 && rule == 2) {
						num_s = num_s + 10;
						give_hint_p2 = 1;
						rule = 3;
					}
					else {
						printf("정답입니다!!!!\n\n");
						break;
					}
				}
				num_r = n2;
			}
			
			else {
				printf("규칙을 어겼습니다. 상대에게 턴을 뺏깁니다.\n\n");
				break_p2 = 1;
				break_p2_n = 2;
			}

		}
		
	} while (turn_p1 < 10 && turn_p2 < 10);
}

