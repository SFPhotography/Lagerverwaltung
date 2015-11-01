// C-Headerdatei lagdat.h
// Definition einer Schnittstelle fuer ein Programm zur Lagerverwaltung
// 2. Prakt.Uebung Programmieren

#ifndef _LAGER_H
#define _LAGER_H

#define MAXCHAR 40

#define lagerdateiname "lager.dat"


struct artikel_t
{
  int artnr;
  char artname[MAXCHAR];
  float preis;
  int bestand;
  int min;
};

int openLager(void);
int readNext(struct artikel_t *);
int closeLager(void);

#endif
