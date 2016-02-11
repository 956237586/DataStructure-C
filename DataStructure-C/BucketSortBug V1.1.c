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
	
	//读入数字
	printf("请输入%d个数字：", SIZE);
	for(i = 0; i < SIZE; i++){
		scanf("%d", &numbers[i]);
	}
	
	//排序
	sort(numbers); 
	//输出结果 
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

//排序函数 
void sort(int numbers[]){
	int bucket[10][SIZE] = {0}; // 定义10个桶
	//每个桶第0号记录桶内数字个数 
	int maxDigit; // 最长几位 
	int i = 0;
	//获得最多位数，确定排序次数 
	maxDigit = getMaxDigit(numbers); 
	//printf("maxDigit = %d\n", maxDigit);

	for(i = 0; i < maxDigit; i++){
		//进行第i位排序
		distribute(i, bucket, numbers);
		//按序归位 
		collect(bucket, numbers);
		//debug(numbers);
	}

}

//获取最大位数 
int getMaxDigit(int numbers[]){
	int maxNumber = getMaxNumber(numbers);
	int maxDigit = getDigit(maxNumber);
	return maxDigit;
}

//获得最大值
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

//获取位数 
int getDigit(int number){
	int digit = 0;
	while(number > 0){
		number /= 10;
		digit++;
	}
	return digit; 
}

//按第i位进行分发 
void distribute(int i, int bucket[10][SIZE], int numbers[]){
	int j = 0;
	int digitNum = 0;
	int pos = 0; 
	//把每个数做分发 
	for(j = 0; j < SIZE; j++){
		//取得第i位的数字 
		digitNum = getDigitNumber(numbers[j], i);
		
		//调试用的代码 
		//printf("numbers[%d] = %d, i = %d, digitNum = %d\n", j, numbers[j], i, digitNum);
		
		//放进桶里(应该放在个数+1的下标位置
		pos = bucket[digitNum][0] + 1;
		bucket[digitNum][pos] = numbers[j];
		bucket[digitNum][0]++; //更新个数 
	}
}

//获取number的第i位 
int getDigitNumber(int number, int i){
	int digitNum = 0; 
	int j = 0; 
	//534 取第0位 4
	//534 取第3位 0
	
	for(j = 0; j < i; j++){
		number /= 10;
	}
	digitNum = number % 10;
	return digitNum;
}

//把桶里数字收回去 
void collect(int bucket[10][SIZE], int numbers[]){
	int i = 0;
	int j = 0;
	int count = 0;
	//处理10个桶 
	for(i = 0; i < 10; i++){
		//处理每个桶中的所有数字，桶底记录了数量 
		for(j = 1; j <= bucket[i][0]; j++){
			numbers[count] = bucket[i][j];
			count++;
		}
		bucket[i][0] = 0; //清空桶 
	}
}
