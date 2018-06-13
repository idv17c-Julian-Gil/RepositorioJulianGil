#pragma once
#include "Header.h"
#include "CRooms.h"
#include "CPlayer.h"
#include "CObjectRoom.h"

//Aqui se toman los inputs

class CScene
{
public:
	CScene();
	virtual~CScene();

public:
	void CreateRooms(unordered_map<string, CRooms>& Rooms);
	void Input(vector<string>& UserInput, unordered_map<string, CRooms> Rooms, string& Union);
	void TakeAction(vector<string> UserInput, unordered_map<string, CRooms> Rooms, string Union);
	void Show_Help(vector<string> UserInput);
	void Objective();
	void SavePlayer(CPlayer Player);
	void LoadPlayer(CPlayer& Player);

public:
	unordered_map<string,CRooms> Rooms;
	string Union;
	vector <string> UserInput;
	CPlayer Player;
	CObjectRoom ObjRoom;
	CRooms Room;
};

