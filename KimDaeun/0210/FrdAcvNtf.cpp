// 20180210.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int activityNotifications(vector <int> expenditure, int d) {
	// Complete this function
	
	
	vector<int> exp;
	int count = 0;
	int median = 0;
	for (int i = d; i < expenditure.size(); i++)
	{
		exp.clear();
		exp.assign(expenditure.begin() + i, expenditure.begin() + i + d);

		for (int j = 0; j < d-1; j++)
		{
			for (int k = j; k < d; k++)
			{
				if (exp[j] < exp[k])
				{
					int temp = exp[j];
					exp[j] = exp[k];
					exp[k] = temp;
				}
			}
		}
		median = exp[d / 2];
		if (median < expenditure[i])
		{
			count += 1;
		}
	}
	return count;
}

int main() {
	int n;
	int d;
	cin >> n >> d;
	vector<int> expenditure(n);
	for (int expenditure_i = 0; expenditure_i < n; expenditure_i++) {
		cin >> expenditure[expenditure_i];
	}
	int result = activityNotifications(expenditure, d);
	cout << result << endl;
	return 0;
}

