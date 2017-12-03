#include <stdio.h>			//<1>
#include <time.h>			//time_t 구조체를 사용하기 위한 헤더

int main()
{
	int input;
	
							//<2>
	double time_cal;		// process 시작 clock수와, 종료직전의 clock수의 차이를  통해 시간을 구함
	time_t start, end;		// process 시작, 죵료직전 순간의 clock을 대입시킬 변수

							//<3>
	start = clock();		// 시작시 clock 대입


							//<4>
	scanf("%d", &input);	//표준 입력 대기, 대기 중이기 때문에 입력을 받기 전까지 clock수는 증가하고 있다.
							//표준 입력 완료부터 code_line을 따라 감

	end = clock();			//종료 시점의 clock체크
							// clock의 차이를 통함 소요 시간 측정
	
	time_cal = (double)(end - start) / CLK_TCK;
	printf("\n\nWe Spent %f Clock Time", time_cal);

	return 0;
}