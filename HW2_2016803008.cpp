#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>

using namespace std;

double arr[1001][1001];
int main()
{
	double maxArray[1001]; // 최댓값 담을 배열
	double minArray[1001]; //최솟값 담을 배열
	double maxCurrentSum = 0; // maxarray에서의 부분 최대값
	double maxSubSum = 0; // maxArray의 subarray합
	double minCurrentSum = 0; //minarray에서의 부분 최대값
	double minSubSum = 0; //minArray의 subarray합
	double minSum = 0; // 최소값 배열에서의 최대값
	double maxSum = 0; //최대값 배열에서의 최대값

	//X,Y 좌표들
	int maxY1 = 0; 
	int maxY2 = 0;
	int maxX2 = 0;
	int maxX1 = 0;
	int minY1 = 0;
	int minY2 = 0;
	int minX2 = 0;
	int minX1 = 0;
	int n;

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) //값 입력
		{
			cin >> arr[i][j];
			maxArray[j] = 0;
			minArray[j] = 0;
		}
	}

	for (int i = 0; i < n; i++) // 세로줄 array에서 부분합 최대값 구하기
	{
		for (int j = i; j < n; j++)
		{
			double temp1 = 0; // 최대값 x1좌표용 temp
			double temp2 = 0; //최소값 x1좌표용 temp
			for (int l = 0; l < n; l++)
			{
				maxArray[l] += arr[l][j];
				minArray[l] += (-1)*arr[l][j]; // min에는 입력값에 -1곱
			}

			for (int k = 0; k < n; k++)
			{
				///////max
				if (maxSubSum < 0) // 만약 부분합이 음수라면 0으로 폐기하고 다시 시작
				{
					maxSubSum = 0;
					maxSubSum += maxArray[k];
					temp1 = k;
				}
				else //양수라면 덧셈
				{
					maxSubSum += maxArray[k]; 
				}
				if (maxCurrentSum < maxSubSum) // 부분합이 최대인 값이 부분값보다 작다면 최신화
				{
					maxCurrentSum = maxSubSum;
				}
				if (maxSum < maxCurrentSum) //해당 배열의 부분 최대값이 전체 배열에서의 최대값보다 크다면 최신화
				{
					maxSum = maxCurrentSum;
					maxX2 = k;
					maxY2 = j;
					maxY1 = i;
					maxX1 = temp1;
				}
				/////////min
				if (minSubSum < 0)
				{
					minSubSum = 0;
					minSubSum += minArray[k];
					temp2 = k;
				}
				else
				{
					minSubSum += minArray[k]; // maxSubSum 
				}
				if (minCurrentSum < minSubSum) //maxCurrentSum 
				{
					minCurrentSum = minSubSum;
				}
				if (minSum < minCurrentSum) //maxsum 
				{
					minSum = minCurrentSum;
					minX2 = k;
					minY2 = j;
					minY1 = i;
					minX1 = temp2;
				}
			}
			maxSubSum = 0;
			maxCurrentSum = 0;
			minSubSum = 0;
			minCurrentSum = 0;
		}
		for (int l = 0; l < n; l++)
		{
			maxArray[l] = 0;
			minArray[l] = 0;
		}
	}

	maxX1++;
	maxY2++;
	maxY1++;
	maxX2++;
	minX1++;
	minY2++;
	minY1++;
	minX2++;
	minSum *= -1; 

	cout << endl;
	cout << "minSum : " << minSum << endl;
	cout << "(" << minX1 << " , " << minY1 << ")" << "";
	cout << "(" << minX2 << " , " << minY2 << ")" << endl;
	cout << "maxSum : " << maxSum << endl;
	cout << "(" <<  maxX1 << " , " << maxY1 << ")" << "";
	cout << "(" <<  maxX2 << " , " << maxY2 << ")" << endl;
}