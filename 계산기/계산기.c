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
