	[문제출제]
	[- 단, while문을 하나만 사용하는 방식과 두 개를 사용하는 방식으로 총 두 개를 만들어본다.]

	- 기본적으로 0의 숫자를 가지고 있는 f가 있다.
	- f는 10씩 증가하며, 총 1000까지만 늘어난다.
	- 그 다음, f가 500까지 다시 10씩 떨어지는 상황을 출력하시오.

## while 1개
```c
	
	int f = 0;
	int d = 0;
	while (1) {
	if (d != 1) {
	f = f + 10;
	printf("%d\n", f);
	if (f == 1000) {
	d = 1;
	}
	}
	else if (d == 1) {
	f = f - 10;
	printf("%d\n", f);
	if (f == 500) {
	break;
	}
	}
	}
```





## while 2개
```c
	int f = 0;
	int d = 0;

	while (1) {
	while (1) {
	if (d == 0) {
	if (f == 1000) {
	d = 1;
	}
	else {

	f = f + 10;
	printf("%d\n", f);
	}
	}
	else if (d == 1) {
	break;
	}
	}

	if (d == 1) {
	if (f == 500) {
	break;
	}
	else {
	f = f - 10;
	printf("%d\n", f);
	}
	}
	}
```
