#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verifyArguments(int argc, char **argv) {

	if (argc != 3) {
		printf("Requires two parameters\n");
		return -1;
	}

	if (strcmp(argv[1], "encode") && strcmp(argv[1], "decode")) {
		printf("first argument must be encode or decode\n");
		return -2;
	}

	return 0;
}

char *readFile(char *inFilename) {

	// open file
	
	FILE *fp = fopen(inFilename, "rt");
	if (!fp) {
		printf("unable to open %s for reading\n", inFilename);
		return NULL;
	}

	// get file size
	
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	if (size <= 0) {
		printf("unable to determine length of %s\n", inFilename);
		return NULL;
	}

	// allocate memory
	
	char *buf = malloc(size+1);

	if (!buf) {
		printf("unable to allocate adequate memory to read %s\n", inFilename);
		return NULL;
	}

	memset(buf, 0, size);
	
	// read file data
	
	int read = fread(buf, 1, size, fp);
	if (read != size) {
		printf("unable to read all bytes from %s\n", inFilename);
	}

	// close file
	
	fclose(fp);
	
	// return file data

	return buf;
}

char *code(char *inBuf) {

	// get length of input buffer
	
	int length = strlen(inBuf);

	// allocate new buffer for coding
	
	char *outBuf = malloc(length+1);
	if (!outBuf) {
		printf("unable to allocate %d bytes for coding", length+1);
		return NULL;
	}

	memset(outBuf, 0, length+1);
	
	// loop through each character
	char *readPtr = inBuf;
	char *writePtr = outBuf;
	while (*readPtr) {
		char c = *readPtr; 
		// if lowercase, encode
		if (c >= 'a' && c <= 'z') {
			c += 13;
			if (c > 'z') {
				c -= 26;
			}
			*writePtr = c;
		}
		// if uppercase, encode
		else if (c >= 'A' && c <= 'Z') {
			c += 13;
			if (c > 'Z') {
				c -= 26;
			}
			*writePtr = c;
		}
		// if neither, copy
		else {
			*writePtr = c;
		}

		// advance pointers
		++readPtr;
		++writePtr;
	}

	// return new buffer
	return outBuf;
}

char *encode(char *inBuf) {
	return code(inBuf);
}

char *decode(char *inBuf) {
	return code(inBuf);
}

int writeFile(char *fileName, char *outBuf) {

	// open file for writing
	FILE *fp = fopen(fileName, "wt");
	if (!fp) {
		printf("unable to open %s for writing\n", fileName);
		return -1;
	}

	// determine number of bytes to write
	
	int num = strlen(outBuf) + 1;
	
	// write bytes to file
	
	fwrite(outBuf, 1, num, fp);
	
	// close file

	fclose(fp);
	return 0;
}

int main(int argc, char **argv) {

	// verify arguments
	
	int result = verifyArguments(argc, argv);
	if (result) {
		return result;
	}

	// read in entire file to encode or decode

	char *inFile = readFile(argv[2]);
	if (inFile == NULL) {
		return -21;
	}

	// encode or decode
	
	char *resultText = NULL;

	if (!strcmp(argv[1], "encode")) {
		resultText = encode(inFile);		
	}
	if (!strcmp(argv[1], "decode")) {
		resultText = decode(inFile);
	}
	
	// write result buffer to file
	int len = strlen(argv[2]);
	len += 8;
	char *outFilename = malloc(len);
	strcpy(outFilename, argv[2]);
	strcat(outFilename, ".out");

	writeFile(outFilename, resultText);

	// clean up
	
	free(outFilename);
	free(resultText);
	free(inFile);

	return 0;
}


