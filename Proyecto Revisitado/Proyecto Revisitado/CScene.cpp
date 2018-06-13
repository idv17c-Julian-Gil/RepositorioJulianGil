#include "CScene.h"

CScene::CScene()
{
}

void CScene::Objective()
{
	string Message = "Tu objetivo es escapar de la plaza y llegar a casa a tiempo para acabar tu proyecto de programacion";
	int x = 0;
	while (Message[x] != '\0')
	{
		cout << Message[x];
		Sleep(60);
		x++;
	}
	cout << '\n' << endl;
}

ofstream& operator<<(ofstream* ofst, CPlayer& Player)
{
	*ofst << Player.m_Location << endl;
	*ofst << Player.m_Victory << endl;
	for (int i = 0; i < Player.m_Inventory.size(); i++)
	{
		*ofst << Player.m_Inventory[i] << endl;
	}
	return *ofst;
}

void CScene::SavePlayer(CPlayer Player)
{
	ofstream *Jugador = new ofstream;
	Jugador->open("Jugador.txt");
	Jugador << Player << endl;
	if (Jugador != nullptr)
		delete Jugador;
	cout << "Partida guardada con exito!!" << '\n' << endl;
}

void CScene::LoadPlayer(CPlayer& Player)
{
	string Name = "Jugador.txt";
	ifstream(Load);
	int x = 1;
	string Word;
	Load.open(Name.c_str(), ios::in);
	if (Load.fail())
	{
		cout << "Hubo un error cargando tu partida..." << endl;
	}
	while (!Load.eof())
	{
		if (x == 1)
		{
			getline(Load, Word);
			Player.m_Location = Word;
		}
		if (x == 2)
		{
			getline(Load, Word);
			if (Word == "0")
				Player.m_Victory = false;
			else
				Player.m_Victory = true;
		}
		if (x == 3)
		{
			getline(Load, Word);
			Player.m_Inventory.push_back(Word);
		}
		x++;
		if (x > 3)
			break;
	}
}

void CScene::CreateRooms(unordered_map<string, CRooms>& Rooms)
{
	CRooms Kiosko;
	Kiosko.m_Name = "Kiosko";
	Kiosko.m_Description = "El centro de la plaza, hay salidas a la calle en las cuatro direcciones cardinales.";
	Kiosko.m_Analyze = "Es un kiosko grande y muy decorado. En la base hay unos botes de basura que estan rebosando de basura que huele bastante mal.";
	Kiosko.m_FirstVisit = false;
	Rooms[Kiosko.m_Name] = Kiosko;

	CRooms Parque_Norte;
	Parque_Norte.m_Name = "Parque entrada norte";
	Parque_Norte.m_Description = "Estas al norte del parque, detras de ti esta la plaza y frente a ti una calle.";
	Parque_Norte.m_Analyze = "Es una camino corto rodeado de arbustos que va del kiosko a la calle. Hay algunas bancas a lo largo del camino y una parece tener varias cajas.";
	Parque_Norte.m_FirstVisit = true;
	Rooms[Parque_Norte.m_Name] = Parque_Norte;

	CRooms Parque_Sur;
	Parque_Sur.m_Name = "Parque entrada sur";
	Parque_Sur.m_Description = "Estas al sur del parque, frente a ti esta una calle y detras esta el kiosko.";
	Parque_Sur.m_Analyze = "El camino hacia la calle esta algo destruido, con hoyos e incluso un auto volteado cerca de la calle. El auto parece tener la cajuela abierta.";
	Parque_Sur.m_FirstVisit = true;
	Rooms[Parque_Sur.m_Name] = Parque_Sur;

	CRooms Parque_Este;
	Parque_Este.m_Name = "Parque entrada este";
	Parque_Este.m_Description = "Estas al este del parque, a tu izquierda hay una calle y a tu derecha esta el kiosko.";
	Parque_Este.m_Analyze = "El kiosko se ve quemado desde ese lado, sobre todo en la parte del techo. Hay un arbusto en llamas cerca del kiosko que emite un olor muy fuerte.";
	Parque_Este.m_FirstVisit = true;
	Rooms[Parque_Este.m_Name] = Parque_Este;

	CRooms Parque_Oeste;
	Parque_Oeste.m_Name = "Parque entrada oeste";
	Parque_Oeste.m_Description = "Estas al oeste del parque, a tu izquierda esta el kiosko y a tu derecha hay una calle.";
	Parque_Oeste.m_Analyze = "Parece ser uno de los lados mejor cuidados del parque, aun hay muchos arbustos y pasto. No parece haber mucho de interes que ver.";
	Parque_Oeste.m_FirstVisit = true;
	Rooms[Parque_Oeste.m_Name] = Parque_Oeste;

	CRooms Entrada_Sur;
	Entrada_Sur.m_Name = "Calle lado sur";
	Entrada_Sur.m_Description = "Estas sobre una calle al sur del parque, frente a ti esta el parque y a ambos lados hay mas calle.";
	Entrada_Sur.m_Analyze = "Parece ser una calle en buenas condiciones con lamparas encendidas, no parece haber nada de interes aqui.";
	Entrada_Sur.m_FirstVisit = true;
	Rooms[Entrada_Sur.m_Name] = Entrada_Sur;

	CRooms Entrada_Norte;
	Entrada_Norte.m_Name = "Calle lado norte";
	Entrada_Norte.m_Description = "Estas sobre una calle al norte del parque, detras de ti esta el parque y a ambos lados hay mas calle.";
	Entrada_Norte.m_Analyze = "Frente a ti hay un gran porton con un candado viejo. Detras de ti esta un cartel que lee 'Plaza Millenio'.";
	Entrada_Norte.m_FirstVisit = true;
	Rooms[Entrada_Norte.m_Name] = Entrada_Norte;

	CRooms Entrada_Oeste;
	Entrada_Oeste.m_Name = "Calle lado oeste";
	Entrada_Oeste.m_Description = "Estas sobre una calle al oeste del parque, a tu derecha se encuentra una de las entradas y tanto enfrente como atras de ti hay mas calle.";
	Entrada_Oeste.m_Analyze = "Es una calle en buenas condiciones con algunas lamparas apagadas. Parece haber un cofre chico pegado a la pared.";
	Entrada_Oeste.m_FirstVisit = true;
	Rooms[Entrada_Oeste.m_Name] = Parque_Oeste;

	CRooms Entrada_Este;
	Entrada_Este.m_Name = "Calle lado este";
	Entrada_Este.m_Description = "Estas sobre una calle al este del parque, a tu izquierda se encuentra una de la entradas y tanto enfrente como detras de ti hay mas calle.";
	Entrada_Este.m_Analyze = "La calle se ve algo maltratada, no se ve nada mas de interes.";
	Entrada_Este.m_FirstVisit = true;
	Rooms[Entrada_Este.m_Name] = Entrada_Este;

	CRooms Esquina_Noreste;
	Esquina_Noreste.m_Name = "Calle interseccion norte con este";
	Esquina_Noreste.m_Description = "Estas en el cruce de calles del norte y este.";
	Esquina_Noreste.m_Analyze = "A lo largo de la calle hay unas barricadas, aparte de eso no hay mucho mas que ver.";
	Esquina_Noreste.m_FirstVisit = true;
	Rooms[Esquina_Noreste.m_Name] = Esquina_Noreste;

	CRooms Esquina_Noroeste;
	Esquina_Noroeste.m_Name = "Calle interseccion norte con oeste";
	Esquina_Noroeste.m_Description = "Estas en el cruce de calles del norte y oeste";
	Esquina_Noroeste.m_Analyze = "Hay un monton de chasis de autos apilados en una esquina. A lo mejor hay algo ahi.";
	Esquina_Noroeste.m_FirstVisit = true;
	Rooms[Esquina_Noroeste.m_Name] = Esquina_Noroeste;

	CRooms Esquina_Sureste;
	Esquina_Sureste.m_Name = "Calle interseccion sur con este";
	Esquina_Sureste.m_Description = "Estas en el cruce de las calles del sur y este.";
	Esquina_Sureste.m_Analyze = "Es una calle en buenas condiciones con lamparas encendidas.";
	Esquina_Sureste.m_FirstVisit = true;
	Rooms[Esquina_Sureste.m_Name] = Esquina_Sureste;

	CRooms Esquina_Suroeste;
	Esquina_Suroeste.m_Name = "Calle interseccion sur con oeste";
	Esquina_Suroeste.m_Description = "Estas en el cruce de las calles del sur y oeste";
	Esquina_Suroeste.m_Analyze = "La calle esta cubierta por muchas plantas y arboles, parece que no le han dado mucho mantenimiento.";
	Esquina_Suroeste.m_FirstVisit = true;
	Rooms[Esquina_Suroeste.m_Name] = Esquina_Suroeste;

	//Aqui se anexan los cuartos y a donde puedes ir
	//Desde el Kiosko
	(Rooms[Kiosko.m_Name]).m_North = Parque_Norte.m_Name;
	(Rooms[Kiosko.m_Name]).m_South = Parque_Sur.m_Name;
	(Rooms[Kiosko.m_Name]).m_East = Parque_Este.m_Name;
	(Rooms[Kiosko.m_Name]).m_West = Parque_Oeste.m_Name;

	//Desde Parque_Norte
	(Rooms[Parque_Norte.m_Name]).m_North = Entrada_Norte.m_Name;
	(Rooms[Parque_Norte.m_Name]).m_South = Kiosko.m_Name;
	(Rooms[Parque_Norte.m_Name]).m_East = "No";
	(Rooms[Parque_Norte.m_Name]).m_West = "No";

	//Desde Parque_Sur
	(Rooms[Parque_Sur.m_Name]).m_North = Kiosko.m_Name;
	(Rooms[Parque_Sur.m_Name]).m_South = Entrada_Sur.m_Name;
	(Rooms[Parque_Sur.m_Name]).m_East = "No";
	(Rooms[Parque_Sur.m_Name]).m_West = "No";

	//Desde Parque_Este
	(Rooms[Parque_Este.m_Name]).m_North = "No";
	(Rooms[Parque_Este.m_Name]).m_South = "No";
	(Rooms[Parque_Este.m_Name]).m_East = Entrada_Este.m_Name;
	(Rooms[Parque_Este.m_Name]).m_West = Kiosko.m_Name;

	//Desde Parque_Oeste
	(Rooms[Parque_Oeste.m_Name]).m_North = "No";
	(Rooms[Parque_Oeste.m_Name]).m_South = "No";
	(Rooms[Parque_Oeste.m_Name]).m_East = Kiosko.m_Name;
	(Rooms[Parque_Oeste.m_Name]).m_West = Entrada_Oeste.m_Name;

	//Desde Entrada_Norte
	(Rooms[Entrada_Norte.m_Name]).m_North = "No"; //Ver como ganar
	(Rooms[Entrada_Norte.m_Name]).m_South = Parque_Norte.m_Name;
	(Rooms[Entrada_Norte.m_Name]).m_East = Esquina_Noreste.m_Name;
	(Rooms[Entrada_Norte.m_Name]).m_West = Esquina_Noroeste.m_Name;

	//Desde Entrada_Sur
	(Rooms[Entrada_Sur.m_Name]).m_North = Parque_Sur.m_Name;
	(Rooms[Entrada_Sur.m_Name]).m_South = "No";
	(Rooms[Entrada_Sur.m_Name]).m_East = Esquina_Sureste.m_Name;
	(Rooms[Entrada_Sur.m_Name]).m_West = Esquina_Suroeste.m_Name;

	//Desde Entrada_Este
	(Rooms[Entrada_Este.m_Name]).m_North = Esquina_Noreste.m_Name;
	(Rooms[Entrada_Este.m_Name]).m_South = Esquina_Sureste.m_Name;
	(Rooms[Entrada_Este.m_Name]).m_East = "No";
	(Rooms[Entrada_Este.m_Name]).m_West = Parque_Este.m_Name;

	//Desde Entrada_Oeste
	(Rooms[Entrada_Oeste.m_Name]).m_North = Esquina_Noroeste.m_Name;
	(Rooms[Entrada_Oeste.m_Name]).m_South = Esquina_Suroeste.m_Name;
	(Rooms[Entrada_Oeste.m_Name]).m_East = Parque_Oeste.m_Name;
	(Rooms[Entrada_Oeste.m_Name]).m_West = "No";

	//Desde Esquina_Noreste
	(Rooms[Esquina_Noreste.m_Name]).m_North = "No";
	(Rooms[Esquina_Noreste.m_Name]).m_South = Entrada_Este.m_Name;
	(Rooms[Esquina_Noreste.m_Name]).m_East = "No";
	(Rooms[Esquina_Noreste.m_Name]).m_West = Entrada_Norte.m_Name;

	//Desde Equina_Noroeste
	(Rooms[Esquina_Noroeste.m_Name]).m_North = "No";
	(Rooms[Esquina_Noroeste.m_Name]).m_South = Entrada_Oeste.m_Name;
	(Rooms[Esquina_Noroeste.m_Name]).m_East = Entrada_Norte.m_Name;
	(Rooms[Esquina_Noroeste.m_Name]).m_West = "No";

	//Desde Esquina_Sureste
	(Rooms[Esquina_Sureste.m_Name]).m_North = Entrada_Este.m_Name;
	(Rooms[Esquina_Sureste.m_Name]).m_South = "No";
	(Rooms[Esquina_Sureste.m_Name]).m_East = "No";
	(Rooms[Esquina_Sureste.m_Name]).m_West = Entrada_Sur.m_Name;

	//Desde Esquina_Suroeste
	(Rooms[Esquina_Suroeste.m_Name]).m_North = Entrada_Oeste.m_Name;
	(Rooms[Esquina_Suroeste.m_Name]).m_South = "No";
	(Rooms[Esquina_Suroeste.m_Name]).m_East = Entrada_Sur.m_Name;
	(Rooms[Esquina_Suroeste.m_Name]).m_West = "No";

	ObjRoom.AssignObj(ObjRoom.Object, ObjRoom.Location, ObjRoom.ObjList);
}

void CScene::Input(vector <string>& UserInput, unordered_map<string, CRooms> Rooms, string& Union)
{
	CScene::CreateRooms(Rooms);
	CScene::Objective();
	while (Player.m_Victory == false)
	{
		cout << "==============================" << "\nQue deseas hacer?" << endl;
		getline(cin, Union);
		Union += ' ';

		int j = 0;
		char Word[20] = { 0 }; //este char se va a ir llenando, se inicializa en 0 para que no haya caracteres basura

		if (Union.size() <= 20)
		{
			for (int i = 0; i < Union.length(); i++)
			{
				if (Union[i] == ' ') //cuando 'Union' llegue a un espacio, 'Word' se va a meter UserInput
				{
					UserInput.push_back(Word);
					for (int p = 0; p < 20; p++)
					{
						Word[p] = 0;
					}
					j = 0; //Para regresar al inicio de la palabra
				}
				else
				{
					Word[j] = tolower(Union[i]);
					j++;
				}
			}
		}
		else
		{
			cout << "No puedo hacer eso..." << '\n' << '\n' << "Puedes:" << endl;
			UserInput.push_back("ayuda");
		}
		CScene::TakeAction(UserInput, Rooms, Union);

		UserInput = {  };
	}
	cout << "\nGracias por jugar!" << '\n' << "Pulsa ENTER para salir..." << endl;
	cin.ignore();
}

void CScene::Show_Help(vector<string> UserInput)
{
	cout << "Ir (seguido por un punto cardinal), Analizar, Agarrar, Guardar, Inventario" << '\n' << endl;
}

void CScene::TakeAction(vector<string> UserInput, unordered_map<string, CRooms> Rooms, string Union) //Aqui se hace la magia
{
	if (UserInput[0] == "ir")
		Player.Move(Player.m_Location, UserInput, Rooms, Union);
	else if (UserInput[0] == "agarrar")
		Player.Grab(Player.m_Location, Player.m_Inventory, ObjRoom.ObjList);
	else if (UserInput[0] == "analizar")
		Room.Show_Analisis(Rooms, Player.m_Location);
	else if (UserInput[0] == "ayuda")
		Show_Help(UserInput);
	else if (UserInput[0] == "inventario")
		Player.Show_Inventory(Player.m_Inventory);
	else if (UserInput[0] == "disparar" || UserInput[0] == "abrir")
	{
		Player.Check_Inventory(Player.m_Inventory, Player.m_Victory);
		Player.Win(Player.m_Location, Player.m_Inventory, Player.m_Victory, Rooms, UserInput);
	}
	else
		cout << "No puedo hacer eso..." << "\n" <<endl;
}

CScene::~CScene()
{
}