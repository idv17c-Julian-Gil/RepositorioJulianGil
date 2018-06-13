#include "CObjectRoom.h"

CObjectRoom::CObjectRoom()
{
}
  
void CObjectRoom::AssignObj(string Object, string Location, unordered_map <string, CObjectRoom>& ObjList)
{
	CObjectRoom Palanca;
	Palanca.Location = "Calle interseccion sur con oeste";
	Palanca.Object = "Palanca";
	ObjList[Palanca.Location] = Palanca;

	CObjectRoom Dientes;
	Dientes.Location = "Calle lado oeste";
	Dientes.Object = "Dientes de llave";
	ObjList[Dientes.Location] = Dientes;

	CObjectRoom Cabeza;
	Cabeza.Location = "Calle lado norte";
	Cabeza.Object = "Cabeza de llave";
	ObjList[Cabeza.Location] = Cabeza;

	CObjectRoom Cuerpo;
	Cuerpo.Location = "Calle lado sur";
	Cuerpo.Object = "Cuerpo de llave";
	ObjList[Cuerpo.Location] = Cuerpo;

	CObjectRoom Bala;
	Bala.Location = "Parque entrada oeste";
	Bala.Object = "Una bala";
	ObjList[Bala.Location] = Bala;

	CObjectRoom Revolver;
	Revolver.Location = "Kiosko";
	Revolver.Object = "Revolver";
	ObjList[Revolver.Location] = Revolver;
	
}

CObjectRoom::~CObjectRoom()
{
}
