

//#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
char message[200];
int main()
{
	scanf("%[^'\n']s", &message);
	printf("%s", message);
	return 0;
}


