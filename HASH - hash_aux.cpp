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
int main()
{
	int k, m;

    cin >> k >> m;
	while(k != 0 && m != 0)
	{
		cout << hash_aux(k, m) << endl;
		cin >> k >> m;
	}
	return 0;
}
