#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

////���õݹ�ʵ��n��k�η�����
//double pow(double n, double k) {
//
//	if (k > 0) {
//		return n * pow(n, (k - 1));
//	}
//	else if (k == 0) {
//		return 1.0;
//	}
//	else {
//		return  1.0 * pow(n, (k + 1)) / n; // return 1.0 / pow(n, -k);  ��ʦ��˼·�Ƚ����ת����K>0�����
//	}
//}
//int main() {
//	int n = 5;
//	int k = -2;
//	double ret = pow(n, k);//powָ�����ʽ����˼
//	printf("ret = %lf\n", ret);
//
//	return 0;
//}


////��ӡˮ�ɻ��� 1-10000
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
//int dig(int num) {//��λ����
//	int count = 0;
//	while (num != 0) {
//		count++;
//		num /= 10;
//	}
//	return count;
//}
//int isNarcNum(int num) {//�ж�ˮ�ɻ�
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


//���½ڣ��ṹ��

//struct Stu {     //����ѧ���ṹ��
//	char name[10];//{}�ڲ�Ϊһϵ������
//	int age;
//	int idNum[12];
//
//}s1,s2,s3;//�����ṹ��Stu��ͬʱ����������������Ϊstruct Stu������ȫ�ֱ���s1-s3��һ�㲻���״������ڷ��գ� ;����ʡ��

////���typedefȥ����ṹ��
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
//	Stu student2;  //ʡ�Զ���дstruct���鷳
//	Stu s = { "�ܳ���", 20, 123456 };
//	printf("%s\n", s.name);
//	printf("%d\n", s.age);
//	myPrint(&s);
//	return 0;
//}
////ͨ��myPrint()�������ýṹ�����s��ʱ�������ַ���:����s ��ַ&s,��ʱ��ַ�Ǹ��Ž⣬��Ϊ����Ҫ��ջ�д���һ��s����ʱ���������ٿ���


////debug release
////f5 ���f9ʹ�ã������������ϵ㴦 -->  ctrl f5ֱ��ִ�У�������е���
////f10�����   f11����� -->f11��������������뺯���ڲ���f10�򲻽��룻shitf f11������ǰ����
////ctrl shitf f5  ���µ�������һ�ϵ㴦
////shift f5ֹͣ����
//#include <stdlib.h>
//int main() {//debug���г̶Ȼ���ѭ�� ��release���л�ֹͣ��˵��release�Դ����������Ӧ���Ż�
//	int i = 0;//release�汾���Ż����ڴ棬��i�Ĵ��λ�ý��еĵ������˴�ʹ�Ǳ�Խ���ָ�벢δָ�����i
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i < 16; i++) {
//		printf("hehe\n");
//		arr[i] = 0;
//		
//	}
// 	system("pause");
//	return 0;
//}








//��дstrcpy�����������Դ���
#include <assert.h>
char*  strcpy(char* copy,const char* source) {//const����
	assert(copy != NULL && source != NULL);//���Թ�ܿ�ָ�������
	//Assertion failed: copy != NULL && source != NULL, file E:\C_code\test_20221005\test_20221005\test.c, line 153
	char* ret = copy;

	while (*source != '\0') {
		*copy = *source;
		source++;
		copy++;
	}
	*copy = '\0';
	return copy;

	////�ݹ�ʵ�֣�
	//if (*source == '\0') {
	//	*copy = '\0';
	//}
	//else {
	//	*copy = *source;
	//	strcpy(++copy, ++source);

	//}

	////��ʦ���Ż���
	//while (*copy++ = *source++) {
	//	
	//}
	//��ʦ���Ż���
	//	�漰��ָ��ĺ���Ӧ�ù�ܿ�ָ�� 1�������ж�NULL
	//if (source != NULL && copy != NULL) {}
	//	��ܿ�ָ�� 2)����assert���� ���ԣ������Բ���������������

	//�Ż���
	//const����char* source  ��ܳ���Ա������� *source = *copy���о���̫���׳����ִ���

	//�Ż���
	//�����ṩ����ֵchar*��������ʽ����
	
	 
}
int main() {

	char str[20] = "Hello World!";
	char copy[20] = "--------------";
	strcpy(copy, NULL);
	printf("copy = %s\n", copy);

	return 0;
}






////��const����ָ������ۣ�
//int main() {
//	const int a = 10;//const���γ���������Ȼ����ͨ��ָ������õ���ʽ����
//	int* const p = &a;//const int* p = &a���޷��޸�*p,��ָ��p�����Կ��Ը�ֵ
//	int b = 33;	     // int * const p = &a���޷��޸�ָ��p���������޸�*p
//	*p  = 20;		//const int * const p -->��*p ��p��ָ���ָ��ı��������ɸ�ֵ
//	//p = &b;
//	printf("a = %d\n", a);
//
//}