#pragma once
#include "Header.h"
#include <iostream>
#include <random>
using namespace std;

// Losowanie planszy
bool testKierunku(int* plansza, int t, int x, int y);
bool testKierunkuO(int* plansza, int x, int y, int maszt);
bool testKierunku321(int* plansza, int t, int x, int y, int maszt);

void czteroMasztowiec(int* plansza, int x, int y, int k);
void Masztowce321(int* plansza, int maszt, int x, int y, int k);

void LosowaniePlanszy(int* plansza);
bool CzyKoniec(int* wsk);

// Funkcje
void DrukujPlansze(int* plansza);
void DrukujPlansze2(int* planszaA, int* planszaB);
void RuchKomputera(int* planszaA, int* wsk);