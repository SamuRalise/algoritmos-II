#include <iostream>
#include <cstring>

using namespace std;

struct dados
{
	char nome[50];
	char curso[50];
	int mat;
};
int main()
{
	dados aluno[10000];
	int n, i = 0, pos;
	char x[50];
	bool flag = false;

	cin >> n;
	do
	{
		cin.ignore();
		cin.getline(aluno[i].nome, 50);
		cin.getline(aluno[i].curso, 50);
		cin >> aluno[i].mat;
		i++;
	}
	while(i < n);
	cin.ignore();
	cin.getline(x, 50);
	
	for(int b = 0; b < n; b++){
		if(strcmp(aluno[b].nome, x) == 0)
		{
			flag = true;
			pos = b;
		}
	}
	if(flag)
	{
		cout << aluno[pos].nome << endl;
		cout << aluno[pos].curso << endl;
		cout << aluno[pos].mat << endl;
	}
	else
		cout << "Aluno nao localizado";

	return 0;
}
