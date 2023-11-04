#include <iostream>
#include <cstring>

using namespace std;

struct dado
{
	char info[50];
	int k;
	int status;
};
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
int hash_insert(dado t[], int m, int k)
{
	int j;
	int i = 0;
	do
	{
		j = dhash(k, m, i);
		if (t[j].status != 1)
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
	while (i != m);

	return -1;
}
int hash_search(dado t[], int m, int k)
{
	int i = 0;
	int j;

	do
	{
		j = dhash(k, m, i);
		if (t[j].k == k)
			return j;
		i++;
	}
	while (t[j].status != 0 && i < m);
	return -1;
}
int hash_remove(dado t[], int m, int k)
{
	int j;

	j = hash_search(t, m, k);
	if (j != -1)
	{
		t[j].status = 2;
		t[j].k = -1;

		return j;
	}
	else
		return -1;
}
int main()
{
	int m, pos, op;
	dado T[100];
	char info[50], x[50];
	int i, k;

	cin >> m;

	for (i = 0; i < m; i++)
	{
		T[i].k = -1;
		T[i].status = 0;
		strcpy(T[i].info, "vazio");
	}

	cin >> op;
	while (op != 5)
	{
		k = 0;
		switch (op)
		{
		case 1:
			cin.ignore();
			cin.getline(info, 50);
			for(int b = 0; b < strlen(info); b++)
				k += (int)info[b];
			pos = hash_insert(T, m, k);
			strcpy(T[pos].info, info);
			break;
		case 2:
			cin.ignore();
			cin.getline(x, 50);
			for(int b = 0; b < strlen(x); b++)
				k += (int)x[b];
			pos = hash_search(T, m, k);
			if(pos == -1)
				cout << x << " nao encontrado" << endl;
			else
				cout << x << " encontrado na posicao " << pos << endl;
			break;
		case 3:
			cin.ignore();
			cin.getline(x, 50);
			for(int b = 0; b < strlen(x); b++)
				k += (int)x[b];
			pos = hash_remove(T, m, k);
			if(pos != -1)
				strcpy(T[pos].info, "vazio");
			break;
		case 4:
			for (int b = 0; b < m; b++)
				cout << T[b].info << endl;
			break;
		}
		cin >> op;
	}
	return 0;
}
