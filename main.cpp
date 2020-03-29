#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

int problem(int n)
{
	if (n==1)
	{
		return 1;
	}
	int cycle_length = 1;
	do
	{
		cycle_length++;
		if (n%2 == 0)
			n = n/2;
		else
			n = 3*n+1;
	} while(n!=1);
	return cycle_length;
}
void get_numbers(int arr[9999])
{
	for (int i = 1; i <= 9999; ++i)
		arr[i-1] = problem(i);
}
int get_max_cycle_length(int a, int b, int arr[9999])
{
	int m = std::max(a, b);
	int n = std::min(a, b);
	if (n == m)
		return arr[n-1];
	int max = 1;
	for (int i = n-1; i < m-1; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
struct Case
{
	int n;
	int m;
	int max;
};
int main()
{
	int arr[9999];;
	// std::cin >> n >> m;
	std::vector<Case> v;
	std::string data;
	Case current;
	while(getline(std::cin, data))
	{
		if (data == "")
			continue;
		sscanf(data.c_str(), "%d %d", &current.m, &current.n);
		v.push_back(current);
	}

	get_numbers(arr);
  	for (std::vector<Case>::iterator it = v.begin() ; it != v.end(); ++it)
  	{
  		it->max = 2;
		it->max = get_max_cycle_length(it->m, it->n, arr);	
	}
	
	for (std::vector<Case>::iterator it = v.begin() ; it != v.end(); ++it)
		std::cout << it->m << " "<< it->n << " " << it->max << std::endl;	
}