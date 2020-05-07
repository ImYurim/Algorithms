## 문제    
    다음과 같은 입력을 받고 출력하시오.




## 예시
    이름 :
    주소 :
    나이 :
    성별 :
    --------출력--------
    이름 : 홍길동
    주소 : 충청북도
    나이 : 15
    성별 : 남자


```c
char name[10];
char address[201];
int age = 0;
char sex[10];

printf("이름:");
scanf("%s", name);

printf("\n주소:");
getchar(); //마지막에 존재하는 null값들을 지워주는 역할을 함.
gets(address);

printf("\n나이:");
scanf("%d", &age);

printf("\n성별:");
scanf("%s", &sex);

printf("\n이름:%s",name);
printf("\n주소:%s", address);
printf("\n나이:%d", age);
printf("\n성별:%s", sex);

```
