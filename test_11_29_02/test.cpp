#include <iostream>
#include <Windows.h>
using namespace std;




int main()
{
	srand((unsigned int)time(NULL));
	int i = 0;
	while (true)
	{
		i++;
		printf("%d ", rand() % 10);
		if (i == 60)
		{
			printf("\n");
			i = 0;
			Sleep(20);
		}
	}

	
	return 0;
}