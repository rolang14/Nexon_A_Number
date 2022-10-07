#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int solution(int number)
{
	int largest = 0;

	for (int x = 0; x < number; x++)
	{
		vector<int> result;

		int temp = pow(x, 2);
		int temp_self = x;

		int count = 1;
		int count_self = 1;

		int anumber = 0;

		//자릿수 계산
		do
		{
			result.push_back(temp % 10);

			temp = temp / 10;
			temp_self = temp_self / 10;

			if (temp != 0)
				count++;

			if (temp_self != 0)
				count_self++;
		} while (temp != 0);

		//A-Number 찾기
		for (int i = 0; i < count_self; i++)
		{
			anumber += result[i] * (pow(10, i));
		}

		if (anumber == x)
		{
			if (largest < x)
				largest = x;
		}
	}

	return largest;
}

int main()
{
	cout << solution(10000);
}