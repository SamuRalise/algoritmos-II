#include <iostream>

using namespace std;

struct dado
{
	int k;
	int status;
};
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
int hash_insert(dado t[], int m, int k)
{
	int j;
	int i = 0;
	do
	{
		j = hash1(k, i, m);
		if(t[j].status != 1)
		{
			t[j].k = k;
			t[j].status = 1;

			return j;
		}
		else
		{
			i++;
		}
	}
	while(i !=  m);

	return -1;
}
int main()
{
	int m;
	dado T[100];
	int i, k = 0;

	cin >> m;

	for(i = 0; i < m; i++)
	{
		T[i].k = -1;
		T[i].status = 0;
	}
	cin >> k;
	while(k != 0)
	{
		hash_insert(T, m, k);
		cin >> k;
	}

	for(int b = 0; b < m; b++)
		cout << T[b].k << " ";

	return 0;
}

