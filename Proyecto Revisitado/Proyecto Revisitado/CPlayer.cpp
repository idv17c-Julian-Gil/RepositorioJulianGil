#include "CPlayer.h"

CPlayer::CPlayer()
{
	m_Location = "Kiosko";
	m_Victory = false;
}

void CPlayer::Move(string& m_Location, vector<string> UserInput, unordered_map<string,CRooms> Rooms, string Union)
{
	int i = 0;
	if (UserInput[1] == "norte")
		i = 1;
	if (UserInput[1] == "sur")
		i = 2;
	if (UserInput[1] == "este")
		i = 3;
	if (UserInput[1] == "oeste")
		i = 4;
	switch (i)
	{
	case 1:
		if (Rooms[m_Location].m_North != "No")
		{
			m_Location = Rooms[m_Location].m_North;
			Room.Show_Description(Rooms, m_Location);
			int x = 0;
			string Message = "Estas en " + m_Location;
			while (Message[x] != '\0')
			{
				cout << Message[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
			if (Rooms[m_Location].m_FirstVisit == true)
				Rooms[m_Location].m_FirstVisit = false;
		}
		else
		{
			string MessageEr = "Ya no puedes ir mas al " + UserInput[1] + '\n'; 
			int x = 0;
			while (MessageEr[x] != '\0')
			{
				cout << MessageEr[x];
				Sleep(60);
				x++;
			}
			cout << "Te quedas en " + m_Location + '\n';
			cout << '\n' << endl;
		}
		break;
	case 2:
		if (Rooms[m_Location].m_South != "No")
		{
			m_Location = Rooms[m_Location].m_South;
			Room.Show_Description(Rooms, m_Location);
			int x = 0;
			string Message = "Estas en " + m_Location;
			while (Message[x] != '\0')
			{
				cout << Message[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
			if (Rooms[m_Location].m_FirstVisit == true)
				Rooms[m_Location].m_FirstVisit = false;

		}
		else
		{
			string MessageEr = "Ya no puedes ir mas al " + UserInput[1] + '\n';
			int x = 0;
			while (MessageEr[x] != '\0')
			{
				cout << MessageEr[x];
				Sleep(60);
				x++;
			}
			cout << "Te quedas en " + m_Location + '\n';
			cout << '\n' << endl;
		}
		break;
	case 3:
		if (Rooms[m_Location].m_East != "No")
		{
			m_Location = Rooms[m_Location].m_East;
			Room.Show_Description(Rooms, m_Location);
			int x = 0;
			string Message = "Estas en " + m_Location;
			while (Message[x] != '\0')
			{
				cout << Message[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
			if (Rooms[m_Location].m_FirstVisit == true)
				Rooms[m_Location].m_FirstVisit = false;
		}
		else
		{
			string MessageEr = "Ya no puedes ir mas al " + UserInput[1] + '\n';
			int x = 0;
			while (MessageEr[x] != '\0')
			{
				cout << MessageEr[x];
				Sleep(60);
				x++;
			}
			cout << "Te quedas en " + m_Location + '\n';
			cout << '\n' << endl;
		}
		break;
	case 4:
		if (Rooms[m_Location].m_West != "No")
		{
			m_Location = Rooms[m_Location].m_West;
			Room.Show_Description(Rooms, m_Location);
			int x = 0;
			string Message = "Estas en " + m_Location;
			while (Message[x] != '\0')
			{
				cout << Message[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
			if (Rooms[m_Location].m_FirstVisit == true)
				Rooms[m_Location].m_FirstVisit = false;
		}
		else
		{
			string MessageEr = "Ya no puedes ir mas al " + UserInput[1] + '\n';
			int x = 0;
			while (MessageEr[x] != '\0')
			{
				cout << MessageEr[x];
				Sleep(60);
				x++;
			}
			cout << "Te quedas en " + m_Location + '\n';
			cout << '\n' << endl;
		}
		break;
	default:
		cout << "No se puede ir a " << UserInput[1] << ", intente otravez..." << endl;
		cout << "Te quedas en " << m_Location << endl << endl;
		break;
	}
}

CPlayer::CPlayer(string Location, vector<string> Inventory, bool Victory)
{
	m_Location = Location;
	m_Inventory = Inventory;
	m_Victory = Victory;
}

void CPlayer::Show_Location(string m_Location)
{
	cout << "Estas en " << m_Location << endl;
}

void CPlayer::Analyze(string m_Location, unordered_map<string, CRooms> Rooms)
{
	cout << Rooms[m_Location].m_Analyze << '\n' << endl;
}

void CPlayer::Show_Inventory(vector<string> m_Inventory)
{
	if (m_Inventory.size() != 0)
	{
		cout << "Traes contigo ";
		for (int i = 0; i < m_Inventory.size(); i++)
			cout << m_Inventory[i] + " ";
		cout << '\n' << endl;
	}
	else
		cout << "No traes nada contigo por el momento." << '\n' << endl;
}

void CPlayer::Check_Inventory(vector<string> m_Inventory, bool& m_Victory)
{
	if (find(m_Inventory.begin(), m_Inventory.end(), "Cuerpo de llave") != m_Inventory.end() && find(m_Inventory.begin(), m_Inventory.end(), "Cabeza de llave") != m_Inventory.end() && find(m_Inventory.begin(), m_Inventory.end(), "Dientes de llave") != m_Inventory.end())
	{
		m_Victory = true;
	}
	if (find(m_Inventory.begin(), m_Inventory.end(), "Revolver") != m_Inventory.end() && find(m_Inventory.begin(), m_Inventory.end(), "Una bala") != m_Inventory.end())
	{
		m_Victory = true;
	}
}

void CPlayer::Win(string m_Location, vector <string> m_Inventory, bool m_Victory, unordered_map <string, CRooms> Rooms, vector<string> UserInput)
{
	bool Check = false;
	if (m_Victory == true)
		Check = true;
	int x=0;

	if (Rooms[m_Location].m_Name == "Calle lado norte" && Check == true && UserInput[0] == "abrir")
	{
		x = 1;
	}
	if (Rooms[m_Location].m_Name == "Calle lado norte" && Check == true && UserInput[0] == "disparar")
	{
		x = 2;
	}

	switch (x)
	{
	case 1:
		cout << "Con las partes que encontraste logras formar una llave y puedes abrir el porton que te evitaba salir." << endl
			<< "Ahora puedes ir a terminar tu proyecto antes de que te reprueben." << endl;
		m_Victory = true;
		break;
	case 2:
		cout << "Decides cargar la bala en el revolver y le disparas al candado. Como estaba muy viejo se hace pedazos al instante y logras escapar." << endl
			<< "Una forma poco ortodoxa de lograr lo que querias, pero funciona. Ahora corre a casa a terminar el trabajo." << endl;
		m_Victory = true;
		break;
	default:
		cout << "No puedes hacer eso..." << endl;
		break;
	}
}

void CPlayer::Grab(string m_Location, vector<string>& m_Inventory, unordered_map<string, CObjectRoom>& ObjList)
{
	if (ObjList[m_Location].Object != "")
	{
		cout << "Agarraste " << ObjList[m_Location].Object << '\n' << endl;
		m_Inventory.push_back(ObjList[m_Location].Object);
		ObjList[m_Location].Object = "";
	}
	else
		cout << "No hay nada que tomar aqui..." << '\n' << endl;

}

CPlayer::~CPlayer()
{
}
