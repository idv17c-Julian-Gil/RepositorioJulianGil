#pragma once
#include"Header.h"

class CRooms
{
public:
	CRooms();
	CRooms(string Name, string Description, string Analyze, bool First_Visit, string North, string South, string East, string West);
	virtual~CRooms();

public:

	void Show_Description(unordered_map<string, CRooms> Rooms, string m_Location);
	void Show_Analisis(unordered_map<string, CRooms> Rooms, string m_Location);

public:
	string m_Name;
	string m_Description;
	string m_Analyze;
	string m_North;
	string m_South;
	string m_East;
	string m_West;
	bool m_FirstVisit;
};

