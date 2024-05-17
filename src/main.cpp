#include "stdio.h"
#include "AllObject/TestObject.h"


int main(int argc, char *argv[])
{
	printf("U1 start\r\n");
	TestObject testObject;
	printf("testObject %d %d\r\n",testObject.GetOne() , testObject.GetTwo());
	printf("U1 end\r\n");
	return 0;
}

