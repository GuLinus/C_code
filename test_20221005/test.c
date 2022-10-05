#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////利用递归实现n的k次方函数
//double pow(double n, double k) {
//
//	if (k > 0) {
//		return n * pow(n, (k - 1));
//	}
//	else if (k == 0) {
//		return 1.0;
//	}
//	else {
//		return  1.0 * pow(n, (k + 1)) / n; // return 1.0 / pow(n, -k);  老师的思路比较巧妙，转化成K>0的情况
//	}
//}
//int main() {
//	int n = 5;
//	int k = -2;
//	double ret = pow(n, k);//pow指数表达式的意思
//	printf("ret = %lf\n", ret);
//
//	return 0;
//}


////打印水仙花数 1-10000
//double pow(int n, int k) {
//	if (k > 0) {
//		return n * pow(n, k - 1);
//	}
//	else if (k == 0) {
//		return 1.0;
//	}
//	else {
//		return 1.0 * pow(n, k + 1) / n;
//	}
//	
//}
//
//int dig(int num) {//几位数？
//	int count = 0;
//	while (num != 0) {
//		count++;
//		num /= 10;
//	}
//	return count;
//}
//int isNarcNum(int num) {//判断水仙花
//	int digit = dig(num);
//	int sum = 0;
//	int number = num;
//	for (int i = 1; i <= digit; i++) {
//		sum += pow((num % 10), digit);
//		num /= 10;
//	}
//	if (sum == number) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//	
//	
//}
//
//void countNarcNum(int min, int max) {
//
//	for (int i = min; i <= max; i++) {
//		if (isNarcNum(i)) {
//			printf("%d\t", i);
//		}
//	}
//}
//
//int main() {
//
//	countNarcNum(1, 1000000);
//	
//	return 0;
//}


//新章节：结构体

//struct Stu {     //定义学生结构体
//	char name[10];//{}内部为一系列属性
//	int age;
//	int idNum[12];
//
//}s1,s2,s3;//声明结构体Stu的同时，创建了数据类型为struct Stu的三个全局变量s1-s3，一般不轻易创，存在风险， ;不可省略

////结合typedef去定义结构体
//typedef struct Stu {     
//	char name[10];
//	int age;
//	int idNum[12];
//
//}Stu;
//
//void myPrint(Stu* s) {
//	int length = sizeof( (*s).idNum) / sizeof(int);
//	printf("name: %s\n", (*s).name);
//	printf("age: %d\n", (*s).age);
//	printf("ID Num: ");
//	for (int i = 0; i < length; i++) {
//		printf("%d", (*s).idNum[i]);
//	}
//	printf("\n");
//}
//
//int main() {
//	struct Stu student1;
//	Stu student2;  //省略额外写struct的麻烦
//	Stu s = { "周城宇", 20, 123456 };
//	printf("%s\n", s.name);
//	printf("%d\n", s.age);
//	myPrint(&s);
//	return 0;
//}
////通过myPrint()函数调用结构体变量s的时候有两种方法:传参s 传址&s,此时传址是更优解，因为不需要在栈中创建一份s的临时变量，减少开销


////debug release
////f5 配合f9使用，快速运行至断点处 -->  ctrl f5直接执行，不会进行调试
////f10逐过程   f11逐语句 -->f11会遇到函数会进入函数内部，f10则不进入；shitf f11跳出当前函数
////ctrl shitf f5  重新调试至第一断点处
////shift f5停止调试
//#include <stdlib.h>
//int main() {//debug运行程度会死循环 但release运行会停止，说明release对代码进行了相应的优化
//	int i = 0;//release版本下优化了内存，将i的存放位置进行的调整，此处使角标越界的指针并未指向变量i
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i < 16; i++) {
//		printf("hehe\n");
//		arr[i] = 0;
//		
//	}
// 	system("pause");
//	return 0;
//}








//编写strcpy函数，并调试代码
#include <assert.h>
char*  strcpy(char* copy,const char* source) {//const修饰
	assert(copy != NULL && source != NULL);//断言规避空指针的问题
	//Assertion failed: copy != NULL && source != NULL, file E:\C_code\test_20221005\test_20221005\test.c, line 153
	char* ret = copy;

	while (*source != '\0') {
		*copy = *source;
		source++;
		copy++;
	}
	*copy = '\0';
	return copy;

	////递归实现：
	//if (*source == '\0') {
	//	*copy = '\0';
	//}
	//else {
	//	*copy = *source;
	//	strcpy(++copy, ++source);

	//}

	////老师的优化①
	//while (*copy++ = *source++) {
	//	
	//}
	//老师的优化②
	//	涉及到指针的函数应该规避空指针 1）条件判断NULL
	//if (source != NULL && copy != NULL) {}
	//	规避空指针 2)调用assert函数 断言，若断言不成立，给出警告

	//优化③
	//const修饰char* source  规避程序员误操作将 *source = *copy，感觉不太容易出这种错误

	//优化④
	//函数提供返回值char*，便于链式访问
	
	 
}
int main() {

	char str[20] = "Hello World!";
	char copy[20] = "--------------";
	strcpy(copy, NULL);
	printf("copy = %s\n", copy);

	return 0;
}






////对const修饰指针的讨论：
//int main() {
//	const int a = 10;//const修饰常变量，依然可以通过指针解引用的形式修饰
//	int* const p = &a;//const int* p = &a后无法修改*p,但指针p本身仍可以赋值
//	int b = 33;	     // int * const p = &a后无法修改指针p，但可以修改*p
//	*p  = 20;		//const int * const p -->锁*p 锁p，指针和指向的变量均不可赋值
//	//p = &b;
//	printf("a = %d\n", a);
//
//}