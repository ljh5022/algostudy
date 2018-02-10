// JourneyToTheMoon.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int journeyToMoon(int n, vector < vector<int> > astronaut) {
	// Complete this function
	vector<vector<int>> country;	//각 나라별로 벡터에 추가해준다.
	bool isFound = false;
	
	for (int i = 0; i < astronaut.size(); i++)
	{
		
		for (int j = 0; j < country.size(); j++)
		{
			//현재 탐색중인 astronaut pair의 0번째 인덱스값이 country배열에 있는지 확인후, true일 경우 county의 해당 위치에 추가 
			if (std::find(country[j].begin(), country[j].end(), astronaut[i][0]) != country[j].end())
			{
				/*for (int k = 0; k < country.size(); k++)
				{
					if (std::find(country[k].begin(), country[k].end(), astronaut[i][1]) != country[k].end())
					{
						// 중복되는 부분을 원래 있던 부분에 추가후 삭제
					}
				}*/
				country[j].push_back(astronaut[i][1]);
				isFound = true;
				break;
			}
			//pair의 1번째 인덱스 값 검사
			else if (find(country[j].begin(), country[j].end(), astronaut[i][1]) != country[j].end())
			{
				country[j].push_back(astronaut[i][0]);
				isFound = true;
				break;
			}
		}
		//country에 존재하지않으면 county에 새롭게 추가
		if (isFound == false)
		{
			vector<int> temp;
			temp.clear();
			temp.push_back(astronaut[i][0]);
			temp.push_back(astronaut[i][1]);
			country.push_back(temp);
		}
		isFound = false;
	}

	//


	
	int countryMembersNum = 0;
	vector<int> countryMembers;		//나라별로 추가된 벡터에서 각 나라별 astronaut 수
	for (int i = 0; i < country.size(); i++)
	{
		countryMembers.push_back(country[i].size());
		countryMembersNum += country[i].size();
	}

	int noShare = 0;			//쉐어하지않는 나라인 멤버수
	noShare = n - countryMembersNum;
	cout << noShare << endl<<endl;
	cout << country.size() << endl << endl;
	cout << country[0].size() << endl << endl;
	cout << country[0][0] << endl << endl;
	cout << country[0][1] << endl << endl;
	cout << countryMembers.size() << endl << endl;


	int result = 0;
	for (int i = 0; i < countryMembers.size(); i++)
	{
		countryMembersNum -= countryMembers[i];		//해당 나라 외 나머지 사람(국가를 쉐어하는)들 수
		result += countryMembersNum* countryMembers[i];			//쉐어하는 사람들
		result += noShare * countryMembers[i];						//쉐어하지않는 사람들
	}
	result += noShare * (noShare - 1) / 2;

	return result;
}

int main() {
	int n;
	int p;
	cin >> n >> p;
	vector< vector<int> > astronaut(p, vector<int>(2));
	for (int astronaut_i = 0; astronaut_i < p; astronaut_i++) {
		for (int astronaut_j = 0; astronaut_j < 2; astronaut_j++) {
			cin >> astronaut[astronaut_i][astronaut_j];
		}
	}
	int result = journeyToMoon(n, astronaut);
	cout << result << endl;
	return 0;
}