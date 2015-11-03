/*
 * main.c
 *
 *  Created on: 02.11.2015
 *      Author: Simon
 */
#include <stdio.h>
#include "lagdat.h"
#include "lagfunc.h"

int iRet=0;
int gesamtzahl=0;
float gesamtwert=0;
int ueberlauf=0; // anzahl der artikel die in array keinen platz habn

int main (void)
{
	iRet=openLager; //Lager öffnen
	if(iRet==-1)
		printf("Die Lagerdatei konnte nicht geöffnet werden!"); //standartausgabe bei Fehler beim öffnen

	while(iRet!=0) //bestimmung der gesamtzahl unterschiedlicher artikel und gesamtwert
	{
		gesamtwert=gesamtwert+(preis x bestand); //bestimmung des Gesamtwert durch multiplizieren von menge und preis
		gesamtzahl++; //erhöhen der gesamtzahl der artikel
		iRet=readnext(struct artikel_t); //iRet erneut setzen
	}
	printf("Gesamtanzahl der Artikel:%d",gesamtzahl); //standartausgabe der anzahl
	printf("Gesamtwert aller Artikel: %f",gesamtwert); ///standartausgaber des Werts



	return 0;
}

