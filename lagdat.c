// C-Quelldatei lagdat.c
// Modul enthaelt Schnittstelle zum Oeffnen,Lesen und Schliessen einer Lagerdatei
// bereitgestelltes Modul fuer ein Program zur Lagerverwaltung
// 2. Prakt. Uebung Programmieren

#include <stdio.h>
#include "lagdat.h"

static FILE *fp = NULL;
int openLager(void) 
{
  int iRet = 0;
  char bestands_datei_name[] = lagerdateiname;

  if (fp!=NULL) //wenn er schon am ende ist und dann null datei schließen
  	closeLager();
  if((fp=fopen(bestands_datei_name,"rb"))==NULL) //öfnnet die lager.dat und zeigt mit pointer auf ersten artikel
  {	printf(" - Dateifehler!\n"); //rb heißt er darf binärdatei lesen
    iRet = -1;
  }
  return iRet;
}


int readNext(struct artikel_t *aptr)
{
  int iRet = -1; //wird als als dateifehler initialisiert
  if(fp!=NULL)
  { if(fread(aptr,sizeof(struct artikel_t),1,fp) > 0) // anzahl der artikel 1, länge ist größe eines artikel_t, artikel auf den fp zeigt
      iRet = 0;
    else
    { closeLager();
    }
  }
  return iRet;
}

int closeLager(void) //speicher wieder freigeben
{
  int iRet = 0;
  if (fp!=NULL)
  { iRet = fclose(fp);
    fp=NULL;
  }
  return iRet;
}

