#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> void write(FILE* f, T t)
{
   fseek(f,0,SEEK_CUR);
   if (fwrite(&t, sizeof(T), 1, f) != 1) {
      cout<< "Error al escribir" << std::endl;
   }
}

template<typename T> T read(FILE* f)
{
   fseek(f,0,SEEK_CUR);
   T t;
   int i=sizeof(T);
   fread(&t,i,1,f);
   return t;
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,sizeof(T)*n,SEEK_SET);
}

template<typename T> int fileSize(FILE* f)
{
  int cont=0;
  T t;
  while(fread(&t,sizeof(T),1,f)){
     cont++;
  }
  return cont;
}

template<typename T> int filePos(FILE* f)
{
   return ftell(f);
}

#endif
