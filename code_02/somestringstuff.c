#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {

	const char* foo = "this is the time for all good men blah blah blah";
	char buf[128];

	strcpy(buf, foo);
	strcat(buf, foo);
	char *loc = strstr(buf, "for");
	strcpy(loc, "to end this class");
	strcpy(buf, "end");
	int len = strlen(buf);
	int size = sizeof(buf);

	printf("%s\n", buf);
	printf("buf is %d bytes long of %d\n", len, size);

	return 0;

}
