#include <iostream>
using namespace std;

char start_time[10];
char end_time[10];

void InputData(void)
{
	cin >> start_time;
	cin >> end_time;
}

int ConvertInt(char * t)
{
	return (t[0] - '0') * 10 + (t[1] - '0');
}

int ComputeTime(void)
{
	int s = ConvertInt(start_time) * 60 + ConvertInt(start_time + 3);
	int e = ConvertInt(end_time) * 60 + ConvertInt(end_time + 3);
	
	if (e < s) return ((60 * 24) - s + e);

	return (e - s);
}

int Solve(void)
{
	int p = 0;
	int t = ComputeTime();
	if (t < 30) return 500;
	p = 500;
	int a = (t - 30) / 10, b = (t - 30) % 10;
	p += ((t - 30) / 10) * 300;
	if (((t - 30) % 10) > 0) p += 300;
	if (p > 30000) p = 30000;
	return p;
}

void OutputData(int sol) {
	cout << sol;
}

int main(void)
{
	int sol = -1;
	InputData();
	sol = Solve();
	OutputData(sol);

	return 0;
}
