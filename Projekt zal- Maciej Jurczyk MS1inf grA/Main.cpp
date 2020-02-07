#include <iostream>
#include "Header.h"
#include <Windows.h>
using namespace std;

int main()
{
MainMenu:
	cout << "   |\\          |\\       ======// //====\\\\ ======= //====\\\\ //===\\\\ () //====\\\\ |\\    || \\\\    //     |\\    |\\    |\\    " << endl;
	cout << "   |X\\         |X\\           //  ||    ||    ||   ||    || ||   ||    ||    || |\\\\   ||  \\\\  //      |X\\   |X\\   |X\\    " << endl;
	cout << "   |XX\\        |XX\\         //   ||    ||    ||   ||    || ||   || || ||    || ||\\\\  ||   \\\\//       |XX\\  |XX\\  |XX\\   " << endl;
	cout << "   |XXX\\       |XXX\\       //    ||====||    ||   ||    || ||===// || ||    || || \\\\ ||    \\/        |XXX\\ |XXX\\ |XXX\\  " << endl;
	cout << "\\__|_____/  \\__|_____/    //     ||    ||    ||   ||    || ||      || ||    || ||  \\\\||    ||     \\__|_____|_____|__/   " << endl;
	cout << " \\      /    \\      /    //      ||    ||    ||   ||    || ||      || ||    || ||   \\\\|    ||      \\               /    " << endl;
	cout << "  \\____/      \\____/    //=====  ||    ||    ||   \\\\====// ||      || \\\\====// ||    \\|    ||       \\_____________/     " << endl;
	cout << endl << endl << endl;
	cout << "                                     W i t a j    w    g r z e:    Z A T O P I O N Y !" << endl << endl << endl << endl << endl;
	cout << "     Wybierz 0:   by rozegrac pojedynek   g r a c z   V S   k o m p u t e r ." << endl << endl;
	cout << "     Wybierz 1:   by rozegrac pojedynek   g r a c z   V S   g r a c z ." << endl << endl;
	cout << "     Wybierz 2:   by opuscic gre." << endl << endl << endl;
	cout << "     W y b i e r a m    t r y b:   ";	short int tryb;	cin >> tryb;

	if (tryb == 2) { return 0; system("pause"); }

	// gracz 1
	system("cls");
	cout << "     W y b r a l e s    t r y b :   ";
	if (tryb == 1) cout << "g r a c z   V S   g r a c z ";
	else	cout << "g r a c z   V S   k o m p u t e r";  cout << endl << endl;
	if (tryb == 1) cout << "G r a c z   p i e r w s z y :" << endl << endl;
	cout << "     W y g e n e r o w a c   p l a n s z e   l o s o w o ?" << endl;
	cout << "     (1 - tak / 0 - nie): ";
	bool losowanie1; cout << "     "; cin >> losowanie1;

	int plansza1[10][10]{}; int* wsk1 = &plansza1[0][0];
	//wyznaczanie planszy gracz 1
	if (losowanie1) // ustalanie planszy gracza nr 1
	{
		bool OK = false;
		do
		{
			std::system("cls");
			LosowaniePlanszy(&plansza1[0][0]);		DrukujPlansze(&plansza1[0][0]); cout << endl;
			cout << "     C z y   t a k i   r o z k l a d   s t a t k o w   C i    o d p o w i a d a ?" << endl;
			cout << "     (1 - tak / 0 - nie):  ";
			cin >> OK;
			if (!OK) memset(plansza1, 0, 10 * 10 * sizeof(int));
		} while (!OK);
	}
	else
	{
		for (int m = 4; m >= 1; m--)
		{
			for (int i = 1; i <= 5 - m; i++)
			{
				std::system("cls");
				bool czy = false;
				DrukujPlansze(&plansza1[0][0]); cout << endl;
				cout << "     Do rozstawienia masz jeden 4-masztowiec, dwa 3-masztowce," << endl;
				cout << "     trzy 2 - masztowce i cztery 1 - masztowce :" << endl;
				cout << "     Podaj najpierw wspolrzedna literowa, a nastepnie wspolrzedne cyfrowa poczatku statku." << endl;
				cout << "     Na samym koncu podaj kierunek zgodnie z klawiatura numeryczna: " << endl;
				cout << "     8 - w gore, 6 - w prawo, 4 - w lewo lub 2 - w dol." << endl << endl << endl;
				cout << "     G d z i e   c h c e s z   u s t a w i c...   " << endl; cout << "     ";
				if (i == 1) cout << "p i e r w s z y   ";
				else if (i == 2) cout << "d r u g i   ";
				else if (i == 3) cout << "t r z e c i   ";
				else cout << "c z w a r t y   ";
				cout << m << " - m a s z t o w i e c :     " << endl;
				int Y, K, X1;
				char Wa, Wb;
				do
				{
					cout << endl << endl;
					cout << "     Pole [a-j] [1-10] : "; cin >> Wa >> Wb; cout << "     [ 8 / 6 / 4 / 2 ] : "; cin >> K;
					bool czyK = (K == 2) || (K == 4) || (K == 6) || (K == 8);
					X1 = static_cast<int>(Wa); Y = static_cast<int>(Wb);
					if (X1 < Y)
					{
						X1 = Y;
						Y = static_cast<int>(Wa);
					}
					if (X1 > 96)
						X1 -= 97;
					else
						X1 -= 65;
					Y -= 49; K = K / 2;
					bool czyW = (X1 >= 0) && (X1 <= 9);
					if (Y == -1) Y = 9;
					if (*(wsk1 + 10 * X1 + Y) == 0 && czyW)
					{
						czy = testKierunku321(wsk1, K, X1, Y, m);
						if (czy && czyK)
							Masztowce321(wsk1, m, X1, Y, K);
						else
							cout << "    B l a d   k i e r u n k u .   W y b i e r z   p o l e   i   k i e r u n e k   p o n o w n i e ! ! !" << endl;
					}
					else
					{
						cout << "     B l a d   p o l a .   W y b i e r z   p o l e   i   k i e r u n e k   p o n o w n i e ! ! !" << endl;
					}
				} while (!czy);
			}
		}
	}
	int plansza2[10][10]{}; int* wsk2 = &plansza2[0][0];
	//plansza gracz 2
	system("cls");
	if (tryb == 1)
	{
		cout << endl << endl;
		cout << "G r a c z   d r u g i :" << endl << endl;
		system("pause"); system("cls");
		cout << "G r a c z   d r u g i :" << endl; cout << endl;
		cout << "     W y g e n e r o w a c   p l a n s z e   l o s o w o ?   ( w p i s z :  1 - j e s l i    t a k   /   0 - j e s l i    n i e)" << endl;
		bool losowanie2; cout << "     "; cin >> losowanie2;
		if (losowanie2) // ustalanie planszy gracza nr 1
		{
			bool OK = false;
			do
			{
				std::system("cls");
				memset(plansza2, 0, 10 * 10 * sizeof(int));
				LosowaniePlanszy(&plansza2[0][0]);		DrukujPlansze(&plansza2[0][0]); cout << endl;
				cout << "     Czy taki rozklad statkow Ci odpowiada?" << endl;
				cout << "     (1 - tak / 0 - nie):  ";
				cin >> OK;
				if (!OK) memset(plansza1, 0, 10 * 10 * sizeof(int));
			} while (!OK);
		}
		else
		{
			for (int m = 4; m >= 1; m--)
			{
				for (int i = 1; i <= 5 - m; i++)
				{

					std::system("cls");
					bool czy = false;
					char wsp[2]{};
					DrukujPlansze(&plansza1[0][0]); cout << endl;
					cout << "     Do rozstawienia masz jeden 4-masztowiec, dwa 3-masztowce," << endl;
					cout << "     trzy 2 - masztowce i cztery 1 - masztowce :" << endl;
					cout << "     Podaj najpierw wspolrzedna literowa, a nastepnie wspolrzedne cyfrowa poczatku statku." << endl;
					cout << "     Na samym koncu podaj kierunek zgodnie z klawiatura numeryczna: " << endl;
					cout << "     8 - w gore, 6 - w prawo, 4 - w lewo lub 2 - w dol." << endl << endl << endl;
					cout << "     G d z i e   c h c e s z   u s t a w i c...   " << endl; cout << "     ";
					if (i == 1) cout << "p i e r w s z y   ";
					else if (i == 2) cout << "d r u g i   ";
					else if (i == 3) cout << "t r z e c i   ";
					else cout << "c z w a r t y   ";
					cout << m << " - m a s z t o w i e c :     " << endl;
					int Y, K, X1;
					char Wa, Wb;
					do
					{
						cout << endl << endl;
						cout << "     Pole [a-j] [1-10] : "; cin >> Wa >> Wb; cout << "     [ 8 / 6 / 4 / 2 ] : "; cin >> K;
						bool czyK = (K == 2) || (K == 4) || (K == 6) || (K == 8);
						X1 = static_cast<int>(Wa); Y = static_cast<int>(Wb);
						if (X1 < Y)
						{
							X1 = Y;
							Y = static_cast<int>(Wa);
						}
						if (X1 > 96)
							X1 -= 97;
						else
							X1 -= 65;
						Y -= 49; K = K / 2;
						bool czyW = (X1 >= 0) && (X1 <= 9);
						if (Y == -1) Y = 9;
						if (*(wsk1 + 10 * X1 + Y) == 0 && czyW)
						{
							czy = testKierunku321(wsk1, K, X1, Y, m);
							if (czy || czyK)
								Masztowce321(wsk1, m, X1, Y, K);
							else
								cout << "    B l a d   k i e r u n k u .  Wybierz pole i kierunek ponownie!!!" << endl;
						}
						else
						{
							cout << "     B l a d   p o l a .  Wybierz pole i kierunek ponownie!!!" << endl;
						}
					} while (!czy);
				}
			}
		}
	}
	else LosowaniePlanszy(&plansza2[0][0]);
	system("cls");
	// ************************************************   ROZGRYWKA   *************************************************

	// plansza b ma postaæ planszy przeciwnika, ka¿de "strzelone" pole zwiêkszamy o 3, a to zostaje odpowiednio odczytane w funkcji drukuj 
	for (int i = 3; i >= 1; i--)
	{
		cout << endl; cout << endl; cout << endl;
		cout << "     G r a   r o z p o c z n i e   s i e   z a . . . " << endl;
		if (i == 3)
		{
			cout << endl;
			cout << "                         =========\\" << endl;
			cout << "                                 ||" << endl;
			cout << "                                 ||" << endl;
			cout << "                                 ||" << endl;
			cout << "                         ==========" << endl;
			cout << "                                 ||" << endl;
			cout << "                                 ||" << endl;
			cout << "                                 ||" << endl;
			cout << "                         =========/" << endl;
		}
		if (i == 2)
		{
			cout << endl;
			cout << "                         /========\\  " << endl;
			cout << "                         ||      // " << endl;
			cout << "                         \\\\     //" << endl;
			cout << "                               //" << endl;
			cout << "                              //" << endl;
			cout << "                             //" << endl;
			cout << "                            //" << endl;
			cout << "                           //    ||" << endl;
			cout << "                          /========" << endl;
		}
		if (i == 1)
		{
			cout << endl;
			cout << "                              /^\\" << endl;
			cout << "                             //||" << endl;
			cout << "                            // ||" << endl;
			cout << "                           //  ||" << endl;
			cout << "                          //   ||" << endl;
			cout << "                               ||" << endl;
			cout << "                               ||" << endl;
			cout << "                               ||" << endl;
			cout << "                               ||" << endl;
		}
		Sleep(997);
		system("cls");
	}
	int plansza10[10][10]{}; int* wsk10 = &plansza10[0][0];
	for (int i{}; i < 10; i++)
	{
		for (int j{}; j < 10; j++)
			*(wsk10 + 10 * i + j) = *(wsk1 + 10 * i + j);
	}
	int plansza20[10][10]{}; int* wsk20 = &plansza20[0][0];
	for (int i{}; i < 10; i++)
	{
		for (int j{}; j < 10; j++)
			*(wsk20 + 10 * i + j) = *(wsk2 + 10 * i + j);
	}
	bool koniec = false;
	int trafionypl[16]{}, * trafiony = &trafionypl[0]; // tablica specjalna do dzia³ania bota
	memset(trafionypl, 0, 16 * sizeof(int));
	trafionypl[10] = 3;
	trafionypl[11] = 2;
	trafionypl[12] = 1;


	while (!koniec)
	{
		bool OK = true;
		if (tryb == 1) { cout << endl << "     K o l e j   g r a c z a   p i e r w s z e g o ." << endl << endl; system("pause"); system("cls"); }
		while (OK)  //ruch gracz 1
		{
			cout << "     G r a c z   p i e r w s z y ." << endl << endl;
			char xa, xb;
			int y, x1;
			DrukujPlansze2(wsk10, wsk20); cout << endl << endl << endl;
			cout << "     G d z i e   c h c e s z   s t r z e l i c ?" << endl;
			cout << "     p o l e  [ A - J ] [ 1 - 10 ] :"; cin >> xa >> xb;
			x1 = static_cast<int>(xa); y = static_cast<int>(xb);
			if (x1 < y)
			{
				x1 = y;
				y = static_cast<int>(xa);
			}
			if (x1 > 96)
				x1 -= 97;
			else
				x1 -= 65;
			y -= 49;
			if (y == -1) y = 9;
			if (*(wsk20 + 10 * x1 + y) >= 2 || x1 < 0 || x1 > 9 || y < 0 || y > 9)
			{
				if (x1 < 0 || x1 > 9 || y < 0 || y > 9)
				{
					cout << endl << endl; cout << "Wybrales pole z po za plansza gry! Wybierz ponownie..." << endl << endl;
					system("pause");
					system("cls");
				}
				else
					if (*(wsk10 + 10 * x1 + y) >= 2)
					{
						cout << endl << endl; cout << "Strzeliles juz wczesniej w te pole! Wybierz ponownie..." << endl << endl;
						system("pause");
						system("cls");
					}
			}
			else
			{
				OK = 1;
				*(wsk20 + 10 * x1 + y) += 3;
				if (*(wsk20 + 10 * x1 + y) == 4)
				{
					cout << endl << endl << "     T r a f i l e s !!!! Wykonaj ruch ponownie." << endl << endl << endl;
					system("pause");
					system("cls");
				}
				else { cout << endl << endl << "     P u d l o ." << endl << endl << endl; OK = false; system("pause"); }
			}
			if (CzyKoniec(wsk20))
			{
				cout << endl << endl << endl << endl << endl;
				if (tryb == 1)
				{
					cout << "     Z  w  y  c  i  e  z  a     g  r  a  c  z  :     P  I  E  R  W  S  Z  Y";
					cout << endl; cout << endl;
					cout << "     G  r  a  t  u  l  a  c  j  e  !  !  !" << endl << endl << endl;
					koniec = true;
					system("pause");
				}
				else
				{
					system("cls"); cout << "     G  r  a  t  u  l  a  c  j  e  !  !  !   W  Y  G  R  A  L  E  S  !";
					koniec = true;
					cout << endl << endl << endl << endl;
					system("pause");
				}
			}
		}
		system("cls");
		if (!koniec)
		{
			if (tryb == 1) // gracz drugi
			{
				bool OK = true;
				cout << endl << "     K o l e j   g r a c z a   d r u g i e g o ." << endl << endl; system("pause"); system("cls");
				while (OK)  //ruch gracz 1
				{
					cout << "     G r a c z   d r u g i ." << endl << endl;
					char xa, xb;
					int y, x1;
					DrukujPlansze2(wsk20, wsk10); cout << endl << endl << endl;
					cout << "     G d z i e   c h c e s z   s t r z e l i c ?" << endl;
					cout << "     p o l e  [ A - J ] [ 1 - 10 ] :"; cin >> xa >> xb;
					x1 = static_cast<int>(xa); y = static_cast<int>(xb);
					if (x1 < y)
					{
						x1 = y;
						y = static_cast<int>(xa);
					}
					if (x1 > 96)
						x1 -= 97;
					else
						x1 -= 65;
					y -= 49;
					if (y == -1) y = 9;
					if (*(wsk10 + 10 * x1 + y) >= 2 || x1 < 0 || x1 > 9 || y < 0 || y > 9) // sprawdzam wskazane pole do ostrzelenia
					{
						if (x1 < 0 || x1 > 9 || y < 0 || y > 9)
						{
							cout << endl << endl; cout << "Wybrales pole z po za plansza gry! Wybierz ponownie..." << endl << endl;
							system("pause");
							system("cls");
						}
						else
							if (*(wsk10 + 10 * x1 + y) >= 2)
							{
								cout << endl << endl; cout << "Strzeliles juz wczesniej w te pole! Wybierz ponownie..." << endl << endl;
								system("pause");
								system("cls");
							}
					}
					else // jeœli pole mo¿na ostrzelaæ...
					{
						OK = 1;
						*(wsk10 + 10 * x1 + y) += 3;
						if (*(wsk10 + 10 * x1 + y) == 4)
						{
							cout << endl << endl << "     T r a f i l e s !!!! Wykonaj ruch ponownie." << endl << endl << endl;
							system("pause");
							system("cls");
						}
						else { cout << endl << endl << "     P u d l o ." << endl << endl << endl; OK = false; system("pause"); }
					}
					if (CzyKoniec(wsk10))
					{
						cout << endl << endl << endl << endl << endl;
						if (tryb == 1)
						{
							cout << "     Z  w  y  c  i  e  z  a     g  r  a  c  z  :    D R U G I ";
							cout << endl; cout << endl;
							cout << "     G  r  a  t  u  l  a  c  j  e  !  !  !" << endl << endl << endl;
							koniec = true;
						}
						else
						{
							system("cls"); cout << "     G  r  a  t  u  l  a  c  j  e  !  !  !   W  Y  G  R  A  L  E  S  !";
							koniec = true;
							cout << endl << endl << endl << endl;
							system("pause");
						}
					}
				}
			}
			else // komputer **********************************************************************************************
			{
				trafionypl[15] = 1;
				int i = 0;
				cout << endl << "T r w a   r u c h   k o m p u t e r a ..." << endl << endl;
				while (*(trafiony + 15) == 1)
				{
					Sleep(2500);
					RuchKomputera(wsk10, trafiony);
					if (*(trafiony + 15) == 1) i++;
				}
				cout << endl;
				if (i == 0)  cout << " Na Twoje szczscie komputer spudlowal!" << endl;
				if (trafiony[13] == 20)
				{
					system("cls");
					cout << endl << endl << endl << endl << endl;
					cout << "     P  R  Z  E  G  R  A  L  E  S  !  !  !";
					system("pause");
					koniec = true;
				}
				cout << endl;
				system("pause");
				system("cls");
			}
		}
	}
	goto MainMenu;
}