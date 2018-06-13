#pragma once
#include "Header.h"

class CObjectRoom
{
public:
	CObjectRoom();
	virtual ~CObjectRoom();

public:
	string Object;
	string Location;
	unordered_map <string, CObjectRoom> ObjList;

public:
	void AssignObj(string Object, string Location, unordered_map <string, CObjectRoom>& ObjList);
};


