#include "Header.h"
#include <iostream>
#include <random>
using namespace std;

// 
random_device doPola;
mt19937 pole(doPola());
uniform_int_distribution <int> disPole(0, 9);
// kierunek
random_device doKierunku;
mt19937 kierunek(doKierunku());
uniform_int_distribution <int> disKierunek(1, 4);

bool testKierunku(int* plansza, int t, int x, int y)
{
	if (t == 4) // góra
	{
		if (x - 4 >= 0)
			return true;
		else
			return false;
	}
	else
	{
		if (t == 3) // prawo
		{
			if (y + 4 <= 9)
				return true;
			else
				return false;
		}
		else
			if (t == 1) // dó³
			{
				if (x + 4 <= 9)
					return true;
				else
					return false;
			}
			else // lewo
			{
				if (y - 4 >= 0)
					return true;
				else
					return false;
			}
	}
}
bool testKierunkuO(int* plansza, int x, int y, int maszt)
{
	if (x - maszt + 1 >= 0 && *(plansza + 10 * (x - maszt + 1) + y) == 0)
		return true;
	else
		if (y + maszt - 1 <= 9 && *(plansza + 10 * x + y + maszt - 1) == 0)
			return true;
		else
			if (x + maszt - 1 <= 9 && *(plansza + 10 * (x + maszt - 1) + y) == 0)
				return true;
			else
				if (y - maszt + 1 >= 0 && *(plansza + 10 * x + y - maszt + 1) == 0)
					return true;
				else
					return false;
}
bool testKierunku321(int* plansza, int t, int x, int y, int maszt)
{
	if (t == 4) // góra
	{
		if (x - maszt + 1 >= 0 && *(plansza + 10 * (x - maszt + 1) + y) == 0)
			return true;
		else
			return false;
	}
	else
	{
		if (t == 3) // prawo
		{
			if (y + maszt - 1 <= 9 && *(plansza + 10 * x + y + maszt - 1) == 0)
				return true;
			else
				return false;
		}
		else
			if (t == 1) // dó³
			{
				if (x + maszt - 1 <= 9 && *(plansza + 10 * (x + maszt - 1) + y) == 0)
					return true;
				else
					return false;
			}
			else // lewo
			{
				if (y - maszt + 1 >= 0 && *(plansza + 10 * x + y - maszt + 1) == 0)
					return true;
				else
					return false;
			}
	}
}
bool CzyKoniec(int* wsk)
{
	int licznik{};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (*(wsk + 10 * i + j) == 4)
				licznik++;
		}
	}
	if (licznik == 20)
		return true;
	else
		return false;
}

void czteroMasztowiec(int* plansza, int x, int y, int k)
{
	if (k == 4)// w góre
	{
		*(plansza + 10 * (x - 1) + y) = 1;
		*(plansza + 10 * (x - 2) + y) = 1;
		*(plansza + 10 * (x - 3) + y) = 1;

		if (y - 1 >= 0) // zakazane pola po lewej
		{
			*(plansza + 10 * x + y - 1) = -1;
			*(plansza + 10 * (x - 1) + y - 1) = -1;
			*(plansza + 10 * (x - 2) + y - 1) = -1;
			*(plansza + 10 * (x - 3) + y - 1) = -1;
			if (x + 1 <= 9) // zakazane pole pod
			{
				*(plansza + 10 * (x + 1) + y - 1) = -1;
			}
			if (x - 4 >= 0) // zakazane pole nad
			{
				*(plansza + 10 * (x - 4) + y - 1) = -1;
			}
		}
		if (y + 1 <= 9) // zakazane pola po prawej
		{
			*(plansza + 10 * x + y + 1) = -1;
			*(plansza + 10 * (x - 1) + y + 1) = -1;
			*(plansza + 10 * (x - 2) + y + 1) = -1;
			*(plansza + 10 * (x - 3) + y + 1) = -1;
			if (x + 1 <= 9) // zakazane pole pod
			{
				*(plansza + 10 * (x + 1) + y + 1) = -1;
			}
			if (x - 4 >= 0) // zakazane pole nad
			{
				*(plansza + 10 * (x - 4) + y + 1) = -1;
			}
		}
		if (x + 1 <= 9) // zakazane pole pod
		{
			*(plansza + 10 * (x + 1) + y) = -1;
		}
		if (x - 4 >= 0) // zakazane pole nad
		{
			*(plansza + 10 * (x - 4) + y) = -1;
		}
	}
	else
		// w prawo
		if (k == 3)
		{
			*(plansza + 10 * x + y + 1) = 1;
			*(plansza + 10 * x + y + 2) = 1;
			*(plansza + 10 * x + y + 3) = 1;

			if (x - 1 >= 0) // zakazane pola nad
			{
				*(plansza + 10 * (x - 1) + y) = -1;
				*(plansza + 10 * (x - 1) + y + 1) = -1;
				*(plansza + 10 * (x - 1) + y + 2) = -1;
				*(plansza + 10 * (x - 1) + y + 3) = -1;
				if (y - 1 >= 0) // zakazane pole po lewej
				{
					*(plansza + 10 * (x - 1) + y - 1) = -1;
				}
				if (y + 4 <= 9) // zakazane pole po prawej
				{
					*(plansza + 10 * (x - 1) + y + 4) = -1;
				}
			}
			if (x + 1 <= 9) // zakazane pola pod
			{
				*(plansza + 10 * (x + 1) + y) = -1;
				*(plansza + 10 * (x + 1) + y + 1) = -1;
				*(plansza + 10 * (x + 1) + y + 2) = -1;
				*(plansza + 10 * (x + 1) + y + 3) = -1;
				if (y - 1 >= 0) // zakazane pole po lewej
				{
					*(plansza + 10 * (x + 1) + y - 1) = -1;
				}
				if (y + 4 <= 9) // zakazane pole po prawej
				{
					*(plansza + 10 * (x + 1) + y + 4) = -1;
				}
			}
			if (y - 1 >= 0) // zakazane pole po lewej
			{
				*(plansza + 10 * (x)+y - 1) = -1;
			}
			if (y + 4 <= 9) // zakazane pole po prawej
			{
				*(plansza + 10 * (x)+y + 4) = -1;
			}
		}
		else
			//w dó³
			if (k == 1)// w góre
			{
				*(plansza + 10 * (x + 1) + y) = 1;
				*(plansza + 10 * (x + 2) + y) = 1;
				*(plansza + 10 * (x + 3) + y) = 1;

				if (y - 1 >= 0) // zakazane pola po lewej
				{
					*(plansza + 10 * (x)+y - 1) = -1;
					*(plansza + 10 * (x + 1) + y - 1) = -1;
					*(plansza + 10 * (x + 2) + y - 1) = -1;
					*(plansza + 10 * (x + 3) + y - 1) = -1;
					if (x + 4 <= 9) // zakazane pole pod
					{
						*(plansza + 10 * (x + 4) + y - 1) = -1;
					}
					if (x - 1 >= 0) // zakazane pole nad
					{
						*(plansza + 10 * (x - 1) + y - 1) = -1;
					}
				}
				if (y + 1 <= 9) // zakazane pola po prawej
				{
					*(plansza + 10 * (x)+y + 1) = -1;
					*(plansza + 10 * (x + 1) + y + 1) = -1;
					*(plansza + 10 * (x + 2) + y + 1) = -1;
					*(plansza + 10 * (x + 3) + y + 1) = -1;
					if (x + 4 <= 9) // zakazane pole pod
					{
						*(plansza + 10 * (x + 4) + y + 1) = -1;
					}
					if (x - 1 >= 0) // zakazane pole nad
					{
						*(plansza + 10 * (x - 1) + y + 1) = -1;
					}
				}
				if (x + 1 <= 9) // zakazane pole pod
				{
					*(plansza + 10 * (x + 4) + y) = -1;
				}
				if (x - 1 >= 0) // zakazane pole nad
				{
					*(plansza + 10 * (x - 1) + y) = -1;
				}
			}
			else
				// w lewo
				if (k == 2)
				{
					*(plansza + 10 * x + y - 1) = 1;
					*(plansza + 10 * x + y - 2) = 1;
					*(plansza + 10 * x + y - 3) = 1;

					if (x - 1 >= 0) // zakazane pola nad
					{
						*(plansza + 10 * (x - 1) + y) = -1;
						*(plansza + 10 * (x - 1) + y - 1) = -1;
						*(plansza + 10 * (x - 1) + y - 2) = -1;
						*(plansza + 10 * (x - 1) + y - 3) = -1;
						if (y - 4 >= 0) // zakazane pole po lewej
						{
							*(plansza + 10 * (x - 1) + y - 4) = -1;
						}
						if (y + 1 <= 9) // zakazane pole po prawej
						{
							*(plansza + 10 * (x - 1) + y + 1) = -1;
						}
					}
					if (x + 1 <= 9) // zakazane pola pod
					{
						*(plansza + 10 * (x + 1) + y) = -1;
						*(plansza + 10 * (x + 1) + y - 1) = -1;
						*(plansza + 10 * (x + 1) + y - 2) = -1;
						*(plansza + 10 * (x + 1) + y - 3) = -1;
						if (y - 4 >= 0) // zakazane pole po lewej
						{
							*(plansza + 10 * (x + 1) + y - 4) = -1;
						}
						if (y + 1 <= 9) // zakazane pole po prawej
						{
							*(plansza + 10 * (x + 1) + y + 1) = -1;
						}
					}
					if (y - 4 >= 0) // zakazane pole po lewej
					{
						*(plansza + 10 * (x)+y - 4) = -1;
					}
					if (y + 1 <= 9) // zakazane pole po prawej
					{
						*(plansza + 10 * x + y + 1) = -1;
					}
				}
}
void Masztowce321(int* plansza, int maszt, int x, int y, int k)
{
	if (k == 4)// w góre
	{
		for (int i = maszt - 1; i >= 0; i--) //zapis pól statku
			*(plansza + 10 * (x - i) + y) = 1;

		if (y - 1 >= 0) // zakazane pola po lewej
		{
			for (int i = maszt - 1; i >= 0; i--)
				*(plansza + 10 * (x - i) + y - 1) = -1;

			if (x + 1 <= 9) // zakazane pole pod
				*(plansza + 10 * (x + 1) + y - 1) = -1;

			if (x - maszt >= 0) // zakazane pole nad
				*(plansza + 10 * (x - maszt) + y - 1) = -1;
		}
		if (y + 1 <= 9) // zakazane pola po prawej
		{
			for (int i = maszt - 1; i >= 0; i--)
				*(plansza + 10 * (x - i) + y + 1) = -1;
			if (x + 1 <= 9) // zakazane pole pod
				*(plansza + 10 * (x + 1) + y + 1) = -1;
			if (x - maszt >= 0) // zakazane pole nad
				*(plansza + 10 * (x - maszt) + y + 1) = -1;
		}
		if (x + 1 <= 9) // zakazane pole pod
			*(plansza + 10 * (x + 1) + y) = -1;
		if (x - maszt >= 0) // zakazane pole nad
			*(plansza + 10 * (x - maszt) + y) = -1;
	}
	else
		// w prawo
		if (k == 3)
		{
			for (int i = maszt - 1; i >= 0; i--)
				*(plansza + 10 * x + y + i) = 1;
			if (x - 1 >= 0) // zakazane pola nad
			{
				for (int i = maszt - 1; i >= 0; i--)
					*(plansza + 10 * (x - 1) + y + i) = -1;
				if (y - 1 >= 0) // zakazane pole po lewej
					*(plansza + 10 * (x - 1) + y - 1) = -1;
				if (y + maszt <= 9) // zakazane pole po prawej
					*(plansza + 10 * (x - 1) + y + maszt) = -1;
			}
			if (x + 1 <= 9) // zakazane pola pod
			{
				for (int i = maszt - 1; i >= 0; i--)
					*(plansza + 10 * (x + 1) + y + i) = -1;
				if (y - 1 >= 0) // zakazane pole po lewej
					*(plansza + 10 * (x + 1) + y - 1) = -1;
				if (y + maszt <= 9) // zakazane pole po prawej
					*(plansza + 10 * (x + 1) + y + maszt) = -1;
			}
			if (y - 1 >= 0) // zakazane pole po lewej
				*(plansza + 10 * x + y - 1) = -1;
			if (y + maszt <= 9) // zakazane pole po prawej
				*(plansza + 10 * x + y + maszt) = -1;
		}
		else
			//w dó³
			if (k == 1)
			{
				for (int i = maszt - 1; i >= 0; i--) //zapis pól statku
					*(plansza + 10 * (x + i) + y) = 1;

				if (y - 1 >= 0) // zakazane pola po lewej
				{
					for (int i = maszt - 1; i >= 0; i--)
						*(plansza + 10 * (x + i) + y - 1) = -1;

					if (x + maszt <= 9) // zakazane pole pod
						*(plansza + 10 * (x + maszt) + y - 1) = -1;

					if (x - 1 >= 0) // zakazane pole nad
						*(plansza + 10 * (x - 1) + y - 1) = -1;
				}
				if (y + 1 <= 9) // zakazane pola po prawej
				{
					for (int i = maszt - 1; i >= 0; i--)
						*(plansza + 10 * (x + i) + y + 1) = -1;
					if (x + maszt <= 9) // zakazane pole pod
						*(plansza + 10 * (x + maszt) + y + 1) = -1;
					if (x - 1 >= 0) // zakazane pole nad
						*(plansza + 10 * (x - 1) + y + 1) = -1;
				}
				if (x + maszt <= 9) // zakazane pole pod
				{
					*(plansza + 10 * (x + maszt) + y) = -1;
				}
				if (x - 1 >= 0) // zakazane pole nad
				{
					*(plansza + 10 * (x - 1) + y) = -1;
				}
			}
			else
				// w lewo
				if (k == 2)
				{
					for (int i = maszt - 1; i >= 0; i--)
						*(plansza + 10 * x + y - i) = 1;
					if (x - 1 >= 0) // zakazane pola nad
					{
						for (int i = maszt - 1; i >= 0; i--)
							*(plansza + 10 * (x - 1) + y - i) = -1;
						if (y - maszt >= 0) // zakazane pole po lewej
							*(plansza + 10 * (x - 1) + y - maszt) = -1;
						if (y + 1 <= 9) // zakazane pole po prawej
							*(plansza + 10 * (x - 1) + y + 1) = -1;
					}
					if (x + 1 <= 9) // zakazane pola pod
					{
						for (int i = maszt - 1; i >= 0; i--)
							*(plansza + 10 * (x + 1) + y - i) = -1;
						if (y - maszt >= 0) // zakazane pole po lewej
							*(plansza + 10 * (x + 1) + y - maszt) = -1;
						if (y + 1 <= 9) // zakazane pole po prawej
							*(plansza + 10 * (x + 1) + y + 1) = -1;
					}
					if (y - maszt >= 0) // zakazane pole po lewej
						*(plansza + 10 * x + y - maszt) = -1;
					if (y + 1 <= 9) // zakazane pole po prawej
						*(plansza + 10 * x + y + 1) = -1;
				}
}

void LosowaniePlanszy(int* plansza)
{	
	// *************************************************************************   4 masztowiec
	int x, y, k; // losowanie miejsca pocz¹tkowego
	x = disPole(pole);
	y = disPole(pole);
	*(plansza + 10 * x + y) = 1;
	//ustawianie w odpowiednim kierunku
	k = disKierunek(kierunek);

	//sprawdzam mo¿liwoœæ zaisnienia okreœlonego 
	while (testKierunku(plansza, k, x, y) == 0)
		k = disKierunek(kierunek);

	czteroMasztowiec(plansza, x, y, k);
	// *************************************************************************   3, 2 i 1 masztowiec
	for (int l = 2, m = 3; l >= 1; l--) // wstawianie 3 trzymasztowców
	{
		x = disPole(pole);
		y = disPole(pole);
		while (*(plansza + 10 * x + y) != 0 || testKierunkuO(plansza, x, y, m) == 0) //sprawdzam czy pole jest wolne
		{
			x = disPole(pole);
			y = disPole(pole);
		}
		k = disKierunek(kierunek); // losowanie kierunku zwrotu
		while (testKierunku321(plansza, k, x, y, m) == 0)//sprawdzam mo¿liwoœæ stworzenia statku wzglêdem odpowiedniego kierunku
			k = disKierunek(kierunek);
		Masztowce321(plansza, m, x, y, k);
	}
	for (int l = 3, m = 2; l >= 1; l--) // wstawianie 2 dwómasztowców
	{
		while (*(plansza + 10 * x + y) != 0 || testKierunkuO(plansza, x, y, m) == 0) //sprawdzam czy pole jest wolne
		{
			x = disPole(pole);
			y = disPole(pole);
		}
		k = disKierunek(kierunek); // losowanie kierunku zwrotu
		while (testKierunku321(plansza, k, x, y, m) == 0)//sprawdzam mo¿liwoœæ zaistnienia okreœlonego statku wzglêdem kierunku
			k = disKierunek(kierunek);
		Masztowce321(plansza, m, x, y, k);
	}
	for (int l = 4, m = 1; l >= 1; l--)
	{
		x = disPole(pole);
		y = disPole(pole);
		while (*(plansza + 10 * x + y) != 0) //sprawdzam czy pole jest wolne
		{
			x = disPole(pole);
			y = disPole(pole);
		}
		Masztowce321(plansza, m, x, y, 1);
	}
}

void DrukujPlansze(int* plansza)
{
	char poz = 205, pion = 186, lgr = 201, pgr = 187, pdl = 188, ldl = 200, ABC = 65;

	for (int i = 0; i <= 9; i++)
	{
		if (i == 0) // tylko pierwszy wiersz
		{
			for (int j = 0; j <= 10; j++)
			{
				if (j != 0)
				{
					if (j == 10) { cout.width(3); cout << 0; }
					else { cout.width(3); cout << j; }
				}
				else
					cout << "   ";
			}
			cout << endl;
			for (int j = 0; j <= 11; j++)
			{
				if (j == 1)
					cout << "   " << lgr;
				if (j >= 2)
					cout << poz << poz << poz;
				if (j == 11)
					cout << pgr;
			}
			cout << endl;
		}
		cout.width(3);
		cout << ABC++ << pion;
		for (int j = 0; j <= 9; j++)
		{
			if (*(plansza+ 10*i+j) == 1)
			{
				cout.width(2);
				cout.fill(' ');
				cout << "X"; cout << " ";
			}
			else
			{
				cout.width(2);
				cout.fill(' ');
				cout << "-" << " ";
			}
		}
		cout << pion;
		cout << endl;
	}
	for (int j = 0; j <= 11; j++)
	{
		if (j == 1)
			cout << "   " << ldl;
		if (j >= 2)
			cout << poz << poz << poz;
		if (j == 11)
			cout << pdl;
	}
}
void DrukujPlansze2 (int* planszaA, int* planszaB)
{
	char poz = 205, pion = 186, lgr = 201, pgr = 187, pdl = 188, ldl = 200, ABC = 65, ABCD = 65, Pd = 158, tr = 207;

	for (int i = 0; i <= 9; i++)
	{
		// tylko pierwszy wiersz
		if (i == 0) 
		{
			cout << "       Twoja plansza:                 Plansza przeciwnika:" << endl;
			for (int j = 0; j <= 10; j++)
			{
				if (j != 0 && j != 10)
				{
					cout.width(2);	cout << j;
				}
				else
					if (j == 10)
					{
						cout.width(2);	cout << 0;
					}
					else cout << "    ";
			}
			cout << "            ";
			for (int j = 0; j <= 10; j++)
			{
				if (j != 0 && j != 10)
				{
					cout.width(2);	cout << j;
				}
				else
					if (j == 10)
					{
						cout.width(2);	cout << 0;
					}
					else cout << "   ";
			}
			cout << endl;
			for (int j = 0; j <= 11; j++)
			{
				if (j == 1)
					cout << "   " << lgr;
				if (j >= 2)
					cout << poz << poz;
				if (j == 11)
					cout << poz << pgr;
			}
			cout << "         ";
			for (int j = 0; j <= 11; j++)
			{
				if (j == 1)
					cout << "   " << lgr;
				if (j >= 2)
					cout << poz << poz;
				if (j == 11)
					cout << poz << pgr;
			}
			cout << endl;
		}
		cout.width(3);		cout << ABC++ << pion;
		for (int j = 0; j <= 9; j++) // plansza gracza
		{
			if (*(planszaA + 10 * i + j) == 1)
			{
				cout.width(2);	cout.fill(' ');	cout << "O";
			}
			else
				if (*(planszaA + 10 * i + j) == 4)
				{
					cout.width(2);	cout.fill(' ');	cout << tr;
				}
				else
					if (*(planszaA + 10 * i + j) == 2 || *(planszaA + 10 * i + j) == 3)
					{
						cout.width(2);	cout.fill(' ');	cout << Pd;
					}
					else cout << " -";
		}

		cout << " " << pion;	cout << "          ";		cout.width(2);		cout << ABCD++ << pion;
		for (int j = 0; j <= 9; j++)
		{
			if (*(planszaB + 10 * i + j) == 4)
			{
				cout.width(2);	cout.fill(' ');	cout << tr;
			}
			else
				if (*(planszaB + 10 * i + j) == 2 || *(planszaB + 10 * i + j) == 3)
				{
					cout.width(2);	cout.fill(' ');	cout << Pd;
				}
				else
				{
					cout.width(2);	cout.fill(' ');	cout << "-";
				}
		}
		cout << " " << pion;
		cout << endl;
	}
	for (int j = 0; j <= 11; j++)
	{
		if (j == 1)
			cout << "   " << ldl;
		if (j >= 2)
			cout << poz << poz;
		if (j == 11)
			cout << poz << pdl;
	}
	cout << "         ";
	for (int j = 0; j <= 11; j++)
	{
		if (j == 1)
			cout << "   " << ldl;
		if (j >= 2)
			cout << poz << poz;
		if (j == 11)
			cout << poz << pdl;
	}
}

void RuchKomputera(int* plansza, int* wsk)
{
	// Tablica specjalna:
	// [0] - czy i ile trafiono w ci¹gu, 0 nie trafiono nic
	// [1 - 4] - w którym kierunku ustawiony jest statek (1- dó³, 2-lewo, 3-prawo, 4-w góre)
	// [5 i 6] - odpowiednio wspó³rzedne x i y pocz¹tku statku
	// [7] - kierunek utworzenia statku
	// [8 i 9] - dynamiczne wspó³rzêdne poprawnych strza³ów 
	// [10-12] - ile x- masztowców zosta³o do zestrzelenia (10-dwóm, 11-trzym, 12-czterym)
	// [13] - licznik ustrzelonych pól statków
	// [14] - sta³a kierunkowa
	// [15] - czy ostatni strza³ by³ trafiony

	int x, y;
	int góra = 4; // jaki najwiêkszy masztowiec zosta³
	if (wsk[12] == 0)
	{
		góra = 3;
		if (wsk[11] == 0)
		{
			góra = 2;
			if (wsk[10] == 0)
				góra = 1;
		}
	}

	if (*wsk == 0 || góra==1)
	{
		x = disPole(pole);
		y = disPole(pole);
		while (*(plansza + 10 * x + y) > 1)
		{
			x = disPole(pole);
			y = disPole(pole);
		}
		*(plansza + 10 * x + y) += 3;
		if (*(plansza + 10 * x + y) == 4) // jeœli trafi³ zaznacza to w tablicy
		{
			// dostêpnoœci s¹siednich pól
			if (x - 1 >= 0) wsk[4] = 1;
			if (*(plansza + 10 * (x - 1) + y) > 1)   wsk[4] = 0;

			if (y + 1 <= 9) wsk[3] = 1;
			if (*(plansza + 10 * x + y + 1) > 1)   wsk[3] = 0;

			if (x + 1 <= 9) wsk[1] = 1;
			if (*(plansza + 10 * (x + 1) + y) > 1)   wsk[1] = 0;

			if (y - 1 >= 0) wsk[2] = 1;
			if (*(plansza + 10 * x + y - 1) > 1)   wsk[2] = 0;

			wsk[0] = 1;
			wsk[13]++;
			wsk[15] = 1;
			wsk[5] = x; wsk[8] = x;
			wsk[6] = y; wsk[9] = y;

			char xa = static_cast<char>(x);	xa += 65;
			y++; if (y == 10) y = 0;
			cout << "Oberwal Twoj statek na: " << xa << y << endl;
		}
		else  wsk[15] = 0;
	}
	else
	{
		int k = wsk[7];
		int x = wsk[8]; int y = wsk[9];

		if (k == 0 || wsk[k] == 0) // jeœli nie mam okreœlonego kierunku strza³u
		{
			//Powtórka:
			k = disKierunek(kierunek);
			while (wsk[k] == 0)		k = disKierunek(kierunek);
		}
		//******************************************************************************************************************************
		if (wsk[1] == 1 || wsk[2] ==1 || wsk[3] == 1 || wsk[4] == 1) //??????
		{
			if (k == 4) // ostrza³ zgodnie z kierunkiem wylosowanym
			{
				*(plansza + 10 * (x - 1) + y) += 3;
				if (*(plansza + 10 * (x - 1) + y) == 4) // jeœli trafi³ uzupe³nia tablice 
				{
					wsk[0]+= 1;
					wsk[13]++;
					wsk[15] = 1;
					wsk[7] = 4;
					wsk[8] = x - 1;
					wsk[9] = y;
					if (*wsk == 2) // przeciwne (boczne) kierunki odpadaj¹
					{
						wsk[3] = 0; wsk[2] = 0;
					} 
					if (*(plansza + 10 * (x - 2) + y) > 1 || (x - 2) < 0 || *wsk== góra)
					{
						wsk[4] = 0;
						wsk[14] = 1;
						wsk[8] = wsk[5];
						wsk[9] = wsk[6];
						wsk[5] = x - 1;
						wsk[6] = y;
					}
					char xa = static_cast<char>(x);	xa += 65-1;
					y++; if (y == 10) y = 0;
					cout << "Oberwal Twoj statek na: " << xa << y << endl;
				}
				else
				{
					wsk[4] = 0;
					wsk[15] = 0;
					if (*wsk > 1)
					{
						wsk[14] = 1;
						wsk[8] = wsk[5];
						wsk[9] = wsk[6];
						wsk[5] = x;
						wsk[6] = y;
					}
				}
			}
			else //**************************************************************************************
				if (k == 1) // ostrza³ zgodnie z kierunkiem wylosowanym
				{
					*(plansza + 10 * (x + 1) + y) += 3;
					if (*(plansza + 10 * (x + 1) + y) == 4) // jeœli trafi³ uzupe³nia tablice 
					{
						wsk[0]+= 1;
						wsk[13]++;
						wsk[15] = 1;
						wsk[7] = 1;
						wsk[8] = x+1;
						wsk[9] = y;
						if (*wsk == 2)
						{
							wsk[2] = 0; wsk[3] = 0;
						} // przeciwne (boczne) kierunki odpadaj¹

						if (*(plansza + 10 * (x + 2) + y) > 1 || (x + 2) > 9 || góra == *wsk)
						{
							wsk[1] = 0;
							wsk[14] = 4;
							wsk[8] = wsk[5];
							wsk[9] = wsk[6];
							wsk[5] = x+1;
							wsk[6] = y;
						}
						char xa = static_cast<char>(x);	xa += 65 +1;
						y++; if (y == 10) y = 0;
						cout << "Oberwal Twoj statek na: " << xa << y << endl;
					}
					else
					{
						wsk[1] = 0;
						wsk[15] = 0;
						if (*wsk > 1)
						{
							wsk[14] = 4;
							wsk[8] = wsk[5];
							wsk[9] = wsk[6];
							wsk[5] = x;
							wsk[6] = y;
						}
					}
				}
				else //**************************************************************************************
					if (k == 3) // ostrza³ zgodnie z kierunkiem wylosowanym
					{
						*(plansza + 10 * x + y + 1) += 3;
						if (*(plansza + 10 * x + y + 1) == 4) // jeœli trafi³ uzupe³nia tablice 
						{
							wsk[0]+=1;
							wsk[13]++;
							wsk[15] = 1;
							wsk[7] = 3;
							wsk[8] = x;
							wsk[9] = y+1;
							if (*wsk == 2)
							{
								wsk[1] = 0; wsk[4] = 0;
							} // przeciwne (boczne) kierunki odpadaj¹
							if (*(plansza + 10 * x + y + 2) > 1 || (y + 2) >9 || góra == *wsk)
							{
								wsk[3] = 0;
								wsk[14] = 2;
								wsk[8] = wsk[5];
								wsk[9] = wsk[6];
								wsk[5] = x;
								wsk[6] = y+1;
							}
							char xa = static_cast<char>(x);	xa += 65;
							y++; if (y == 10) y = 0; y++;
							cout << "Oberwal Twoj statek na: " << xa << y << endl;
						}
						else
						{
							wsk[3] = 0;
							wsk[15] = 0;
							if (*wsk > 1)
							{
								wsk[14] = 2;
								wsk[8] = wsk[5];
								wsk[9] = wsk[6];
								wsk[5] = x;
								wsk[6] = y;
							}
						}
					}
					else //**************************************************************************************
						if (k == 2) // ostrza³ zgodnie z kierunkiem wylosowanym
						{
							*(plansza + 10 * x + y - 1) += 3;
							if (*(plansza + 10 * x + y - 1) == 4) // jeœli trafi³ uzupe³nia tablice 
							{
								wsk[0]+=1;
								wsk[13]++;
								wsk[15] = 1;
								wsk[7] = 2;
								wsk[8] = x;
								wsk[9] = y-1;
								if (*wsk == 2)
								{
									wsk[1] = 0; wsk[4] = 0;
								} // przeciwne (boczne) kierunki odpadaj¹

								if (*(plansza + 10 * x + y - 2) > 1 || (y - 2) < 0 || góra == *wsk)
								{
									wsk[2] = 0;
									wsk[14] = 3;
									wsk[8] = wsk[5];
									wsk[9] = wsk[6];
									wsk[5] = x;
									wsk[6] = y-1;
								}
								char xa = static_cast<char>(x);	xa += 65;
								y++; if (y == 10) y = 0; y--;
								cout << "Oberwal Twoj statek na: " << xa << y << endl;
							}
							else
							{
								wsk[2] = 0;
								wsk[15] = 0;
								if (*wsk > 1)
								{
									wsk[14] = 3;
									wsk[8] = wsk[5];
									wsk[9] = wsk[6];
									wsk[5] = x;
									wsk[6] = y;
								}
							}
						}
		}
	}

	x = wsk[5], y = wsk[6];
	int maszt = 0;
	int k = wsk[14];
	if (góra == *wsk) // jeœli trafi³em najwiêkszy mo¿liwy statek
	{
		maszt = góra;
		if (góra != 1) wsk[8 + góra]--;
		for (int j = 0; j < 10; j++)
			wsk[j] = 0;
		wsk[14] = 0;
		cout << "HA!!!! Wlasnie zatopilem Twoj " << góra << "-masztowiec." << endl;
	}
	if (wsk[1] == 0 && wsk[2] == 0 && wsk[3] == 0 && wsk[4] == 0 && *wsk!=0) // zestrzelono mniej ni¿ góra-masztowiec
	{
		maszt = wsk[0];
		if (maszt != 1) wsk[8 + maszt]--;
		for (int j = 0; j < 10; j++)
			wsk[j] = 0;
		wsk[14] = 0;
		cout << "HA!!!! Zatopilem Twoj " << maszt << "-masztowiec." << endl;
		if (maszt == 1) k = 4;
	}
	if (maszt > 0)
	{
		if (k == 4)
		{
			if (y - 1 >= 0) // zakazane pola po lewej
			{
				for (int i = maszt - 1; i >= 0; i--)
					if (*(plansza + 10 * (x - i) + y - 1) < 1) *(plansza + 10 * (x - i) + y - 1) += 3;

				if (x + 1 <= 9 && *(plansza + 10 * (x +1) + y - 1) <1) // zakazane pole pod
					*(plansza + 10 * (x + 1) + y - 1) += 3;

				if (x - maszt >= 0 && *(plansza + 10 * (x - maszt) + y - 1) <1) // zakazane pole nad
					*(plansza + 10 * (x - maszt) + y - 1) += 3;
			}
			if (y + 1 <= 9) // zakazane pola po prawej
			{
				for (int i = maszt - 1; i >= 0; i--)
					if (*(plansza + 10 * (x - i) + y + 1) < 1 )   *(plansza + 10 * (x - i) + y + 1) += 3;
				if (x + 1 <= 9 && *(plansza + 10 * (x + 1) + y + 1) <1) // zakazane pole pod
					*(plansza + 10 * (x + 1) + y + 1) += 3;
				if (x - maszt >= 0 && *(plansza + 10 * (x - maszt) + y + 1) <1) // zakazane pole nad
					*(plansza + 10 * (x - maszt) + y + 1) += 3;
			}
			if (x + 1 <= 9 && *(plansza + 10 * (x + 1) + y) <1) // zakazane pole pod
				*(plansza + 10 * (x + 1) + y) += 3;
			if (x - maszt >= 0 && *(plansza + 10 * (x - maszt) + y) <1) // zakazane pole nad
				*(plansza + 10 * (x - maszt) + y) += 3;
		}
		else
			//w dó³
			if (k == 1)
			{
				if (y - 1 >= 0) // zakazane pola po lewej
				{
					for (int i = maszt - 1; i >= 0; i--)
						if (*(plansza + 10 * (x + i) + y - 1) < 1)   *(plansza + 10 * (x + i) + y - 1) += 3;

					if (x + maszt <= 9 && *(plansza + 10 * (x + maszt) + y - 1)<1) // zakazane pole pod
						*(plansza + 10 * (x + maszt) + y - 1) += 3;

					if (x - 1 >= 0 && *(plansza + 10 * (x - 1) + y - 1) <1) // zakazane pole nad
						*(plansza + 10 * (x - 1) + y - 1) += 3;
				}
				if (y + 1 <= 9) // zakazane pola po prawej
				{
					for (int i = maszt - 1; i >= 0; i--)
						if (*(plansza + 10 * (x + i) + y + 1) < 1)   *(plansza + 10 * (x + i) + y + 1) += 3;
					if (x + maszt <= 9 && *(plansza + 10 * (x + maszt) + y + 1) <1) // zakazane pole pod
						*(plansza + 10 * (x + maszt) + y + 1) += 3;
					if (x - 1 >= 0 && *(plansza + 10 * (x - 1) + y + 1) <1) // zakazane pole nad
						*(plansza + 10 * (x - 1) + y + 1) += 3;
				}
				if (x + maszt <= 9 && *(plansza + 10 * (x + maszt) + y) <1) // zakazane pole pod
					*(plansza + 10 * (x + maszt) + y) += 3;
				if (x - 1 >= 0 && *(plansza + 10 * (x - 1) + y) <1) // zakazane pole nad
					*(plansza + 10 * (x - 1) + y) += 3;
			}
			else
				// w prawo
				if (k == 3)
				{
					if (x - 1 >= 0) // zakazane pola nad
					{
						for (int i = maszt - 1; i >= 0; i--)
							if (*(plansza + 10 * (x - 1) + y + i) < 1)   *(plansza + 10 * (x - 1) + y + i) += 3;
						if (y - 1 >= 0 && *(plansza + 10 * (x - 1) + y - 1) <1) // zakazane pole po lewej
							*(plansza + 10 * (x - 1) + y - 1) += 3;
						if (y + maszt <= 9 && *(plansza + 10 * (x - 1) + y + maszt)<1) // zakazane pole po prawej
							*(plansza + 10 * (x - 1) + y + maszt) += 3;
					}
					if (x + 1 <= 9) // zakazane pola pod
					{
						for (int i = maszt - 1; i >= 0; i--)
							if (*(plansza + 10 * (x + 1) + y + i) < 1)   *(plansza + 10 * (x + 1) + y + i) += 3;
						if (y - 1 >= 0 && * (plansza + 10 * (x + 1) + y - 1)<1) // zakazane pole po lewej
							*(plansza + 10 * (x + 1) + y - 1) += 3;
						if (y + maszt <= 9 && *(plansza + 10 * (x + 1) + y + maszt)<1) // zakazane pole po prawej
							*(plansza + 10 * (x + 1) + y + maszt) += 3;
					}
					if (y - 1 >= 0 && *(plansza + 10 * x + y - 1)<1) // zakazane pole po lewej
						*(plansza + 10 * x + y - 1) += 3;
					if (y + maszt <= 9 && *(plansza + 10 * x + y + maszt)<1) // zakazane pole po prawej
						*(plansza + 10 * x + y + maszt) += 3;
				}
				else
					// w lewo
					if (k == 2)
					{
						if (x - 1 >= 0) // zakazane pola nad
						{
							for (int i = maszt - 1; i >= 0; i--)
								if (*(plansza + 10 * (x - 1) + y - i) < 1)   *(plansza + 10 * (x - 1) + y - i) += 3;
							if (y - maszt >= 0 && *(plansza + 10 * (x - 1) + y - maszt)<1) // zakazane pole po lewej
								*(plansza + 10 * (x - 1) + y - maszt) += 3;
							if (y + 1 <= 9 && *(plansza + 10 * (x - 1) + y + 1)<1) // zakazane pole po prawej
								*(plansza + 10 * (x - 1) + y + 1) += 3;
						}
						if (x + 1 <= 9) // zakazane pola pod
						{
							for (int i = maszt - 1; i >= 0; i--)
								if (*(plansza + 10 * (x + 1) + y - i) < 1)   *(plansza + 10 * (x + 1) + y - i) += 3;
							if (y - maszt >= 0 && *(plansza + 10 * (x + 1) + y - maszt)<1) // zakazane pole po lewej
								*(plansza + 10 * (x + 1) + y - maszt) += 3;
							if (y + 1 <= 9 && *(plansza + 10 * (x + 1) + y + 1)<1) // zakazane pole po prawej
								*(plansza + 10 * (x + 1) + y + 1) += 3;
						}
						if (y - maszt >= 0 && *(plansza + 10 * x + y - maszt)<1) // zakazane pole po lewej
							*(plansza + 10 * x + y - maszt) += 3;
						if (y + 1 <= 9 && *(plansza + 10 * x + y + 1)<1) // zakazane pole po prawej
							*(plansza + 10 * x + y + 1) += 3;
					}
	}	// koniec otaczania pola statku
} //koniec funkcji