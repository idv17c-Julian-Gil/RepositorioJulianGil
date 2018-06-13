#pragma once
#include "Header.h"
#include "CObjectRoom.h"
#include "CRooms.h"
//Aqui va el movimiento

class CPlayer
{
public:
	CPlayer();
	CPlayer(string Location, vector<string> Inventory, bool Victory);
	virtual~CPlayer();

public:
	string m_Location;
	vector<string> m_Inventory;
	bool m_Victory; //Checar si va aqui
	CRooms Room;

public:
	void Show_Location(string m_Location);
	void Show_Inventory(vector<string> m_Inventory);
	void Check_Inventory(vector<string> m_Inventory, bool& m_Victory);
	void Win(string m_Location, vector <string> m_Inventory, bool m_Victory, unordered_map <string, CRooms> Rooms, vector<string> UserInput);
	void Move(string& m_Location, vector<string> UserInput, unordered_map<string, CRooms> Rooms, string Union);
	void Grab(string m_Location, vector<string>& m_Inventory, unordered_map<string, CObjectRoom>& ObjList);
	void Analyze(string m_Location, unordered_map<string, CRooms> Rooms);
};

