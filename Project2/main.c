#define _CRT_SECURE_NO_WARNINGS
#include "OrthogonalList.h"
#include "sch_struct.h"
struct St_Crs* stcr;


//������
int main()
{
	stcr = ReadFromFile();

	managerlogin();

	//SaveToFile(stcr);
	g_DestroySt_Crs(stcr);
	return 0;
}
