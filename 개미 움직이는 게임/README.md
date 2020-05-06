## 문제
	0ㅡㅡㅡㅡㅡ개미1>>ㅡㅡㅡㅡㅡ<<개미2ㅡㅡㅡㅡㅡ개미3>>ㅡㅡㅡㅡㅡ24

	===규칙===

	한 선당 1분으로 잡는다.

	개미가 서로 부딪치게 되면 반대편으로 움직인다.

	각각 떨어지는 시간차를 계산하고, 등수를 매긴다. (먼저 떨어지는 개미가 일등!)

	각각 현재 화면에 보이는 개미의 위치.

	1번개미 : 6번째위치
	2번 개미 : 12번째위치
	3번 개미 : 18번째위치



```c
#include <stdio.h>

int main() {
	int a1 = 6;
	int a1_d = 1;
	int a1_t = 0;
	int a1_f = 0;
	int a2 = 12;
	int a2_d = 0;
	int a2_t = 0;
	int a2_f = 0;
	int a3 = 18;
	int a3_d = 1;
	int a3_t = 0;
	int a3_f = 0;
	int r = 1;
	int t = 0;
	int t_rank[4];
	int t_rank_used[4] = {0};
	int t_rank_d[4];
	int t_rank_dir[4];

	printf("0ㅡㅡㅡㅡㅡ개미1>>ㅡㅡㅡㅡㅡ<<개미2ㅡㅡㅡㅡㅡ개미3>>ㅡㅡㅡㅡㅡ24\n\n\n");

	while (a1_f == 0 || a2_f == 0 || a3_f == 0) {

		printf("\n\n\n");
		if (!(a1 == 0 || a1 == 24) || !(a2 == 0 || a2 == 24) || !(a3 == 0 || a3 == 24)) {
			if (!(a1 == 0 || a1 == 24)) {
				if (a1_d == 1) {
					a1++;
				}
				else if (a1_d == 0) {
					a1--;
				}
				printf("개미 1의 자리는 %d번째 입니다.\n", a1);

				a1_t++;
			}

			if (!(a2 == 0 || a2 == 24)) {
				if (a2_d == 1) {
					a2++;
				}
				else if (a2_d == 0) {
					a2--;
				}
				printf("개미 2의 자리는 %d번째 입니다.\n", a2);
				a2_t++;
			}

			if (!(a3 == 0 || a3 == 24)) {
				if (a3_d == 1) {
					a3++;
				}
				else if (a3_d == 0) {
					a3--;
				}
				printf("개미 3의 자리는 %d번째 입니다.\n", a3);
				a3_t++;
			}

		
			t_rank_d[0] = a1;
			t_rank_d[1] = a2;
			t_rank_d[2] = a3;
			t_rank_used[1] = 0;
			t_rank_used[2] = 0;
			t_rank_used[3] = 0;

			for (int i = 1; i < 3; i++) {
				if (t_rank_d[i] < t_rank_d[i - 1]) {
					t = t_rank_d[i];
					t_rank_d[i] = t_rank_d[i - 1];
					t_rank_d[i - 1] = t;
				}
			}

			for (int i = 0; i < 3; i++) {
				if (t_rank_d[i] == a1 && t_rank_used[1]==0){
					t_rank[i] = 1;
					t_rank_dir[i] = a1_d;
					t_rank_used[1] = 1;
				}
				else if (t_rank_d[i] == a2 && t_rank_used[2]==0) {
					t_rank[i] = 2;
					t_rank_dir[i] = a2_d;
					t_rank_used[2] = 1;
				}
				else if(t_rank_d[i] == a3 && t_rank_used[3] == 0){
					t_rank[i] = 3;
					t_rank_dir[i] = a3_d;
					t_rank_used[3] = 1;
				}
			}


			printf("0");
			if (t_rank_d[0] != 0) {
				for (int i = 0; i < t_rank_d[0]; i++) {
					printf("-");
				}

				if (t_rank_dir[0] == 0) {
					printf("<<");
				}

				printf("개미 %d", t_rank[0]);

				if (t_rank_dir[0] == 1) {
					printf(">>");
				}
			}


			if (t_rank_d[1] != 0) {
				for (int i = t_rank_d[0] + 1; i < t_rank_d[1]; i++) {
					printf("-");
				}
				if (t_rank_dir[1] == 0) {
					printf("<<");
				}
				printf("개미 %d", t_rank[1]);

				if (t_rank_dir[1] == 1) {
					printf(">>");
				}

			}


			if (t_rank_d[2] != 0) {
				for (int i = t_rank_d[1] + 1; i < t_rank_d[2]; i++) {
					printf("-");
				}
				if (t_rank_d[2] != 24) {
					if (t_rank_dir[2] == 0) {
						printf("<<");
					}
					printf("개미 %d", t_rank[2]);

					if (t_rank_dir[2] == 1) {
						printf(">>");
					}
				}
								
				
			}
			if (t_rank_d[2] != 24) {
				for (int i = t_rank_d[2] + 1; i < 24; i++) {
					printf("-");
				}
			}
			printf("24\n\n");




			if (a1 == a2 && a1_f == 0 && a2_f == 0) {
				printf("개미 1과 개미 2가 충돌하였습니다.\n\n");
				if (a1_d == 1) {
					a1_d = 0;
					printf("개미 1의 방향이 왼쪽으로 바뀌었습니다.\n\n");
				}
				else if (a1_d == 0) {
					a1_d = 1;
					printf("개미 1의 방향이 오른쪽으로 바뀌었습니다.\n\n");
				}
				if (a2_d == 1) {
					a2_d = 0;
					printf("개미 2의 방향이 왼쪽으로 바뀌었습니다.\n\n");
				}
				else if (a2_d == 0) {
					a2_d = 1;
					printf("개미 2의 방향이 오른쪽으로 바뀌었습니다.\n\n");
				}
			}
			if (a1 == a3 && a1_f == 0 && a3_f == 0) {
				printf("개미 1과 개미 3이 충돌하였습니다.\n\n");
				if (a1_d == 1) {
					printf("개미 1의 방향이 왼쪽으로 바뀌었습니다.\n\n");
					a1_d = 0;
				}
				else if (a1_d == 0) {
					a1_d = 1;
					printf("개미 1의 방향이 오른쪽으로 바뀌었습니다.\n\n");
				}

				if (a3_d == 1) {
					printf("개미 3의 방향이 왼쪽으로 바뀌었습니다.\n\n");
					a3_d = 0;
				}
				else if (a3_d == 0) {
					printf("개미 3의 방향이 오른쪽으로 바뀌었습니다.\n\n");
					a3_d = 1;
				}
			}

			if (a2 == a3 && a3_f == 0 && a2_f == 0) {
				printf("개미 2와 개미 3이 충돌하였습니다.\n\n");
				if (a2_d == 1) {
					printf("개미 2의 방향이 왼쪽으로 바뀌었습니다.\n\n");
					a2_d = 0;
				}
				else if (a2_d == 0) {
					a2_d = 1;
					printf("개미 2의 방향이 오른쪽으로 바뀌었습니다.\n\n");
				}

				if (a3_d == 1) {
					printf("개미 3의 방향이 왼쪽으로 바뀌었습니다.\n\n");
					a3_d = 0;
				}
				else if (a3_d == 0) {
					printf("개미 3의 방향이 오른쪽으로 바뀌었습니다.\n\n");
					a3_d = 1;
				}
			}
		}
		if (a1 == 0 || a1 == 24 || a2 == 0 || a2 == 24 || a3 == 0 || a3 == 24) {
			if ((a1 == 0 || a1 == 24) && a1_f == 0) {
				printf("개미1이 %d등 입니다. 걸린 시간은 %d 입니다.\n\n", r, a1_t);
				a1_f = 1;
				r++;
			}
			if ((a2 == 0 || a2 == 24) && a2_f == 0) {
				printf("개미2이 %d등 입니다. 걸린 시간은 %d 입니다.\n\n", r, a2_t);
				a2_f = 1;
				r++;
			}
			if ((a3 == 0 || a3 == 24) && a3_f == 0) {
				printf("개미3이 %d등 입니다. 걸린 시간은 %d 입니다.\n\n", r, a3_t);
				a3_f = 1;
				r++;
			}

		}

	}

}
```
