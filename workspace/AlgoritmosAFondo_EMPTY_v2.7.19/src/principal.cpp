#ifndef _MAIN
#define _MAIN

#include <iostream>
#include <cstring>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte1/MultidimColl.hpp"
#include "principal.hpp"
using namespace std;
struct Fecha
{
   int fecha; //dd/mm/aaaa
};
struct Hora
{
   int HDInicio;
};
struct TurnoPre
{
   int idRes;
   int idPac;
   int idPra;
   Fecha fPra;
   Hora hPra;
};

struct Practica
{
   int idPra;
   char desc[100];
   int nTurnos;
   int idProf; //id profesional
};

struct TAceptado
{
   int idCli;
   int idPra;
   Fecha f;
   Hora hDd;
   Hora hHh;
};
struct TRechazado
{
   int idRes;
   char Motivo;
};

Map<int, Practica> subirPractica()
{

   return
   {};
}

int calcularHora(int m, int hDTruno)
{
   int cant = m*20;
   if(((m*60)+cant)>24){
      return 0;
   }
   return(m*60)+cant;
}

int HorasTotales(Map<int, Practica> MPractica, TurnoPre turn, Map<int, TRechazado>& MRechazdo)
{
   Practica m = mapGet<int, Practica>(MPractica,turn.idPra);
   if( m==NULL )
   {
      TRechazado rech = { turn.idRes, "no se encontro la Practica" };
      mapPut(MRechazdo,turn.idRes,rech);
      return 0;
   }
   else
      if( m.idProf<0 )
      {
         TRechazado rech = { turn.idRes, "Existe la practica, pero no Tiene asociado un Profecional" };
         mapPut(MRechazdo,turn.idRes,rech);
         return 0;
      }
      else
      {
         int hTotales = calcularHora(m.nTurnos,turn.hPra.HDInicio);
         if( hTotales==0)
         {
            TRechazado rech = { turn.idRes, "La practica dura mas de 20horas" };
            mapPut(MRechazdo,turn.idRes,rech);
            return 0;
         }
         else
         {
            return hTotales;
         }
      }
}

bool hayReserva(TurnoPre turn, Map<int, TAceptado> MAceptado, int HhH, Map<int, TRechazado>& MRechazdo)
{
   TAceptado m = mapGet<int, TAceptado>(MAceptado,turn.fPra.fecha);
   if( m==NULL )
   {
      //no hay reservas para ese dia
      return true;
   }
   else
      if( HhH<m.hDd||turn.hPra.HDInicio>m.hHh )
      {
         //si no hay solapa
         return true;
      }
      else
      {
         //se ecnotro la reserca pero se solapa
         TRechazado rech = { turn.idRes, "El turno solicitado se solapa" };
         mapPut(MRechazdo,turn.idRes,rech);
         return false;
      }

}
void cargarAceptados(Map<int, TAceptado>& MAceptado,TurnoPre turn,int HhH){
   //carga todo al Map MAceptado
}

void procesarPunto1(Map<int, Practica> MPractica, TurnoPre turn, Map<int, TAceptado>& MAceptado, Map<int, TRechazado>& MRechazdo)
{
   int HhH = HorasTotales(MPractica,turn,MRechazdo);
   if( hayReserva(turn,MAceptado,HhH,MRechazdo)&&HhH!=0 )
   {
      cargarAceptados(MAceptado,turn,HhH);
   }
}

void crearArchAcept(Map<int, TAceptado> MAceptado){
   //cargo el MAceptado en un archivo
}
void crearArchNoAcept(Map<int, TRechazado> MRechazdo){
   //cargo el MRechazado en un archivo
}
int main()
{
   Map<int, Practica> MPractica = subirPractica();
   Map<int, TAceptado> MAceptado;
   Map<int, TRechazado> MRechazdo;
   FILE* f = fopen("TURNOS PRE.dat","r+b");
   TurnoPre turn = read<TurnoPre>(f);
   while( !feof(f) )
   {
      //cargo los aceptados y rechazados
      procesarPunto1(MPractica,turn,MAceptado,MRechazdo);

      TurnoPre turn = read<TurnoPre>(f);
   }
   crearArchAcept(MAceptado);
   crearArchNoAcept(MRechazdo);
   fclose(f);
}//faltan terminar funciones que no son dificiles pero me dio el tiempo para terminar
//el Tad Fecha y Hora esta mal usado pero no me dio tiempo a cambiar todo

#endif
