#include <stdio.h>			//<1>
#include <time.h>			//time_t ����ü�� ����ϱ� ���� ���

int main()
{
	int input;
	
							//<2>
	double time_cal;		// process ���� clock����, ���������� clock���� ���̸�  ���� �ð��� ����
	time_t start, end;		// process ����, �շ����� ������ clock�� ���Խ�ų ����

							//<3>
	start = clock();		// ���۽� clock ����


							//<4>
	scanf("%d", &input);	//ǥ�� �Է� ���, ��� ���̱� ������ �Է��� �ޱ� ������ clock���� �����ϰ� �ִ�.
							//ǥ�� �Է� �Ϸ���� code_line�� ���� ��

	end = clock();			//���� ������ clocküũ
							// clock�� ���̸� ���� �ҿ� �ð� ����
	
	time_cal = (double)(end - start) / CLK_TCK;
	printf("\n\nWe Spent %f Clock Time", time_cal);

	return 0;
}