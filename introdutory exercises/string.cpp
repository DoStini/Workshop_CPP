/**
* Escolher dois nomes diferentes atrav�s de substring, para duas vari�veis diferentes
* Concatenar os nomes numa �nica vari�vel
* Mostrar essa vari�vel no ecr�
* Descobrir o tamanho dessa nova string e mostrar tamb�m no ecr�
*/

#include <iostream>

using namespace std;

int main()
{
	char name1[256];
	cout << "Hey there, what's your full name?\n";
	cin.getline(name1, 256);
	string name = string(name1);
	cout << name;


	return 0;
}
