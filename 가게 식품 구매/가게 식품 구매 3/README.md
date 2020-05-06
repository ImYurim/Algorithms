## 문제

    철수와 영희가 있다.
    둘이 가진 금액은 애초에 10000원으로,
    처음에 용돈을 추가적으로 입력받는다.
    추가적으로 입력받으면, 현재 금액이 얼마인지 바로 나타내준 후,
    바로 떡볶이 금액, 우동 금액, 과자 금액을 입력받는다.
    위에서 입력받은 액수가 개당 1000원이라고 가정한다.
    그리고
    바로 떡볶이를 몇 개를 주문하겠냐는 메시지가 나타난다.
    이곳에서 20개를 입력하게 되면 10000원밖에 없기 때문에 10000원이 부족해진다.

    =문단2=
    돈이 부족하지 않을 경우에는 떡볶이는 얼마였고, 현재 얼마가 남았다는 문장과 함께
    바로 우동이나 과자로 넘어가면 되지만,
    만약 위처럼 돈이 부족한 경우에는 현재 얼마가 부족한지 나타내고,
    추가적으로 용돈을 입력받을 수 있게 만든다.
    추가적으로 용돈을 받은 경우에는 얼마를 입력받아서 얼마가 되었다. 라는 형식으로 나타내면 되고,
    그곳에서 돈이 부족하지 않은 경우에는 떡볶이는 얼마였고, 현재 얼마가 남았다는 문장과 함께
    다음 우동 혹은 과자로 넘어가게 된다.

    위 문단2에서 이미 추가적으로 용돈을 받았기 때문에 더는 용돈을 추가적으로 받을 수 없다.
    이후 우동이나 과자에서 돈이 부족한 경우 주인장에게 쫓겨나게 만드시오.

    단, 이 문제의 경우에는 떡볶이에서 돈이 부족하지 않은 경우의 수도 존재한다.
    만약 떡볶이에서 돈이 부족하지 않았다면, 우동에서 부족했을 경우, 그리고 과자에서도 부족하다면 과자에서 쫓겨났을 것이고,
    만약 돈이 아예 부족하지 않을 만큼 많이 받은 경우에는 셋 다 사먹어도 무난하게 마지막 금액이 나타났을 수 있다.

    즉, 상황에 따라 변화하는 알고리즘을 작성하시오.
    
```c
char p1[5] = "철수";
	char p2[5] = "영희";
	int p1_money = 10000;
	int p2_money = 10000;
	int add_money;
	int e_add_money;
	int total_money;
	int need_money;
	int ricecake;
	int n_ricecake;
	int t_ricecake;
	int cookie;
	int n_cookie;
	int t_cookie;
	int noodle;
	int n_noodle;
	int t_noodle;
	int finish;

	printf(" 용돈을 추가로 입력하세요:");
	scanf("%d", &add_money);
	total_money = p1_money + p2_money + add_money;
	printf("현재 %s와 %s의 용돈의 합은 %d원 입니다.\n", p1,p2,total_money);


	printf("떡볶이의 금액을 입력하세요:");
	scanf("%d", &ricecake);
	printf("우동의 금액을 입력하세요:");
	scanf("%d", &noodle);
	printf("과자의 금액을 입력하세요:");
	scanf("%d", &cookie);
	
	printf("떡볶이를 몇 개 주문하시겠습니까? 개 수를 입력하시오:");
	scanf("%d", &n_ricecake);
	t_ricecake = n_ricecake * ricecake;
	
	if (t_ricecake <= total_money) {
		total_money = total_money - t_ricecake;
		printf("떡볶이는 %d원 이었습니다. 현재 남은 돈은 %d입니다.", t_ricecake, total_money);
	}
	if (t_ricecake > total_money) {
		need_money = t_ricecake - total_money;
		printf("%d원이 부족합니다.\n 추가로 용돈을 입력하시오:",need_money);
		scanf("%d", &add_money);
		total_money = total_money + add_money;
		e_add_money = 1;
		printf("용돈이 추가되어, 총 용돈은 %d원입니다.", total_money);
		total_money = total_money - t_ricecake;
		printf("떡볶이는 %d원 이었습니다. 현재 남은 돈은 %d입니다.", t_ricecake, total_money);
	}
	


 
		printf("\n우동을 몇 개 주문하시겠습니까? 개 수를 입력하시오:");
		scanf("%d", &n_noodle);
		t_noodle = n_noodle * noodle;
		if (t_noodle > total_money) {
			need_money = t_noodle - total_money;
			if (e_add_money == 1) {
				printf("용돈이 부족하나 용돈을 추가로 받은 적이 있습니다. 주인장에게 쫓겨나게 되었습니다.");
				return 0;
			}
			if (e_add_money != 1) {
				printf("%d원이 부족합니다. 추가로 용돈을 입력하시오:", need_money);
				scanf("%d", &add_money);
				total_money = total_money + add_money;
				e_add_money = 1;
				printf("용돈이 추가되어 총 용돈은 %d원입니다.\n", total_money);
			}
		}
		if (t_noodle <= total_money) {
			total_money = total_money - t_noodle;
			printf("우동 %d원 이었습니다. 현재 남은 돈은 %d입니다.", t_noodle, total_money);
		}
		if (e_add_money==1 && (t_noodle > total_money)&& finish!=1) {
			printf("추가했어도 용돈이 부족합니다.주인장에게 쫓겨나게 되었습니다. ");
			finish = 1;
		}



	if (finish != 1) {
		printf("\n과자를 몇 개 주문하시겠습니까? 개 수를 입력하시오:");
		scanf("%d", &n_cookie);
		t_cookie = n_cookie * cookie;
		if (t_cookie > total_money) {
			need_money = t_cookie - total_money;
			if (e_add_money == 1) {
				printf("용돈이 부족하나 용돈을 추가로 받은 적이 있습니다. 주인장에게 쫓겨나게 되었습니다.");
				return 0;
			}
			if (e_add_money != 1) {
				printf("%d원이 부족합니다.\n 추가로 용돈을 입력하시오:", need_money);
				scanf("%d", &add_money);
				total_money = total_money + add_money;
				e_add_money = 1;
			}
		}
		if (t_cookie <= total_money) {
			total_money = total_money - t_cookie;
			printf("과자는 %d원 이었습니다. 현재 남은 돈은 %d입니다.", t_cookie, total_money);
		}
		if (e_add_money==1&& (t_cookie > total_money)&&finish!=1) {
			printf("추가했어도 용돈이 부족합니다.주인장에게 쫓겨나게 되었습니다. ");
		}
	}

```
