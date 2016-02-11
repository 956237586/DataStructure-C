#include <stdio.h>
#define SIZE 6

int getMaxDigit(int numbers[]);
int getMaxNumber(int numbers[]);
int getDigit(int number);
void sort(int numbers[]);
void distribute(int i, int bucket[10][SIZE], int numbers[]);
int getDigitNumber(int number, int i);
void collect(int bucket[10][SIZE], int numbers[]);
void debug(int numbers[]);

int main(){
	int numbers[SIZE];//= {49, 16, 1859, 15915, 456, 79841,};
	int i = 0;
	
	//��������
	printf("������%d�����֣�", SIZE);
	for(i = 0; i < SIZE; i++){
		scanf("%d", &numbers[i]);
	}
	
	//����
	sort(numbers); 
	//������ 
	for(i = 0; i < SIZE; i++){
		printf("numbers[%d] = %d\n", i, numbers[i]);
	}
	
	return 0;
}

void debug(int numbers[]){
	int i = 0;
	printf("debug\n");
	for(i = 0; i < SIZE; i++){
		printf("numbers[%d] = %d\n", i, numbers[i]);
	}
	printf("debug\n");
}

//������ 
void sort(int numbers[]){
	int bucket[10][SIZE] = {0}; // ����10��Ͱ
	//ÿ��Ͱ��0�ż�¼Ͱ�����ָ��� 
	int maxDigit; // ���λ 
	int i = 0;
	//������λ����ȷ��������� 
	maxDigit = getMaxDigit(numbers); 
	//printf("maxDigit = %d\n", maxDigit);

	for(i = 0; i < maxDigit; i++){
		//���е�iλ����
		distribute(i, bucket, numbers);
		//�����λ 
		collect(bucket, numbers);
		//debug(numbers);
	}

}

//��ȡ���λ�� 
int getMaxDigit(int numbers[]){
	int maxNumber = getMaxNumber(numbers);
	int maxDigit = getDigit(maxNumber);
	return maxDigit;
}

//������ֵ
int getMaxNumber(int numbers[]){
	int i = 0;
	int max = numbers[0];
	for(i = 1; i < SIZE; i++){
		if(max < numbers[i]){
			max = numbers[i];
		}
	}
	return max;
}

//��ȡλ�� 
int getDigit(int number){
	int digit = 0;
	while(number > 0){
		number /= 10;
		digit++;
	}
	return digit; 
}

//����iλ���зַ� 
void distribute(int i, int bucket[10][SIZE], int numbers[]){
	int j = 0;
	int digitNum = 0;
	int pos = 0; 
	//��ÿ�������ַ� 
	for(j = 0; j < SIZE; j++){
		//ȡ�õ�iλ������ 
		digitNum = getDigitNumber(numbers[j], i);
		
		//�����õĴ��� 
		//printf("numbers[%d] = %d, i = %d, digitNum = %d\n", j, numbers[j], i, digitNum);
		
		//�Ž�Ͱ��(Ӧ�÷��ڸ���+1���±�λ��
		pos = bucket[digitNum][0] + 1;
		bucket[digitNum][pos] = numbers[j];
		bucket[digitNum][0]++; //���¸��� 
	}
}

//��ȡnumber�ĵ�iλ 
int getDigitNumber(int number, int i){
	int digitNum = 0; 
	int j = 0; 
	//534 ȡ��0λ 4
	//534 ȡ��3λ 0
	
	for(j = 0; j < i; j++){
		number /= 10;
	}
	digitNum = number % 10;
	return digitNum;
}

//��Ͱ�������ջ�ȥ 
void collect(int bucket[10][SIZE], int numbers[]){
	int i = 0;
	int j = 0;
	int count = 0;
	//����10��Ͱ 
	for(i = 0; i < 10; i++){
		//����ÿ��Ͱ�е��������֣�Ͱ�׼�¼������ 
		for(j = 1; j <= bucket[i][0]; j++){
			numbers[count] = bucket[i][j];
			count++;
		}
		bucket[i][0] = 0; //���Ͱ 
	}
}
