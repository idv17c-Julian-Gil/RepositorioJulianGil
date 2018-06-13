#include "CRooms.h"


CRooms::CRooms()
{

}

CRooms::CRooms(string Name, string Description, string Analyze, bool FirstVisit, string North, string South, string East, string West)
{
	m_Name = Name;
	m_Description = Description;
	m_Analyze = Analyze;
	m_FirstVisit = FirstVisit;
	m_North = North;
	m_South = South;
	m_East = East;
	m_West = West;
}

void CRooms::Show_Analisis(unordered_map<string, CRooms> Rooms, string m_Location)
{
	cout << Rooms[m_Location].m_Analyze << '\n' << endl;;
}

void CRooms::Show_Description(unordered_map<string, CRooms> Rooms, string m_Location)
{
	cout << Rooms[m_Location].m_Description << endl;
}

CRooms::~CRooms()
{
}
