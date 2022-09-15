#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

	if (argc != 3) {
		printf("Expected two filenames as parameters\n");
		return -1;
	}

	char *in = argv[1];
	char *out = argv[2];

	FILE *fp = fopen(in, "rt");
	if (fp == NULL) {
		printf("Unable to open %s for reading\n", in);
		return -2;
	}

	fseek(fp, 0, SEEK_END);
	int count = ftell(fp);
	fseek(fp, SEEK_SET, 0);

	char *buf = malloc(count);
	if (buf == NULL) {
		fclose(fp);
		printf("unable to read from file %s", in);
		return -3;
	}

	fread(buf, 1, count, fp);
	fclose(fp);
	
	FILE *outFP = fopen(out, "wt");
	if (outFP == NULL) {
		free(buf);
		printf("unable to open %s for writing\n", out);
		return -4;
	}

	fwrite(buf, 1, count, outFP);
	fclose(outFP);

	free(buf);

	return 0;

}


