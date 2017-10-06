#include<iostream>
#include <vector>
using namespace std;

vector<vector<char>> secret_map(int n, int* arr, int* arr2);
vector<char> dectochar(int number, int n);

int main()
{
	int n = 5;
	int arr1[5] = { 9, 20, 28, 18, 11 };
	int arr2[5] = { 30, 1, 21, 17, 28 };
	vector<vector<char>> v(secret_map(5, arr1, arr2));

	for (vector<vector<char>>::iterator iter = v.begin(); iter != v.end(); iter++) {
		for (vector<char>::iterator iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++)
			cout << *iter2;
		cout << endl;
	}
	return 0;
}

vector<vector<char>> secret_map(int n, int* arr, int* arr2)
{
	vector<vector<char>> result(n);
	vector<int> number(n);

	for (int i = 0; i < number.size(); i++) 
		number[i] = arr[i] | arr2[i];

	for (int i = 0; i < number.size(); i++) {
		result[i] = dectochar(number[i],n);
	}
	
	return result;
}

vector<char> dectochar(int number, int n)
{
	vector<char> row(n);
	int namuge , i=0;
	while (number > 0) {
		namuge = number % 2;
		row[i] = (namuge == 1) ?  '#' : ' ';
		i++;
		number = number / 2;
	}
	return row;
}
