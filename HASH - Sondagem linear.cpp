#include <iostream>

using namespace std;

int hash_aux(int k, int m)
{
	int res;

	res = k % m;

	if(res < 0)
		res += m;

	return res;
}
int hash1(int k, int i, int m)
{
	return (hash_aux(k, m) + i) % m;
}
int main()
{
	int k, m;

	cin >> k >> m;

	for(int i = 0; i < m; i++)
	{
		cout << hash1(k, i, m) << " ";
	}
	return 0;
}
