#include <iostream>

using namespace std;

int h1(int k, int m)
{
	int res;

	res = k % m;

	if (res < 0)
		res += m;

	return res;
}
int h2(int k, int m)
{
    int res;
    
    res = 1 + (k % (m - 1));

    if (res < 0)
		res += m;

	return res;
}
int dhash(int k, int m, int i)
{
	return (h1(k, m) + i * h2(k, m)) % m;
}
int main()
{
	int k, m;

	cin >> k >> m ;

	for(int i = 0; i < m; i++)
	{
		cout << dhash(k, m, i) << " ";
	}
	return 0;
}
