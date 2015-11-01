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

  if (fp!=NULL)
  	closeLager();
  if((fp=fopen(bestands_datei_name,"rb"))==NULL)
  {	printf(" - Dateifehler!\n");
    iRet = -1;
  }
  return iRet;
}


int readNext(struct artikel_t * aptr) 
{
  int iRet = -1; 
  if(fp!=NULL)
  { if(fread(aptr,sizeof(struct artikel_t),1,fp) > 0)
      iRet = 0;
    else
    { closeLager();
    }
  }
  return iRet;
}

int closeLager(void)
{
  int iRet = 0;
  if (fp!=NULL)
  { iRet = fclose(fp);
    fp=NULL;
  }
  return iRet;
}

