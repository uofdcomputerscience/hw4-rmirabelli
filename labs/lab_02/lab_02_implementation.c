#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* numbers[] = 	{
		"78.6807",
		"101.5249",
		"118.73",
		"101.3658",
		"114.8930",
		"32.1272",
		"103.7544",
		"111.878",
		"110.7923",
		"110.7709",
		"97.4440",
		"32.8165",
		"103.4492",
		"105.3042",
		"118.7987",
		"101.2503",
		"32.2327",
		"121.1729",
		"111.8840",
		"117.2612",
		"32.4303",
		"117.3169",
		"112.7709",
		"44.7157",
		"32.9560",
		"110.933",
		"101.3099",
		"118.278",
		"101.1816",
		"114.5335",
		"32.9097",
		"103.7826",
		"111.3512",
		"110.9267",
		"110.3810",
		"97.7633",
		"32.979",
		"108.9149",
		"101.6579",
		"116.8821",
		"32.1967",
		"121.672",
		"111.1393",
		"117.9336",
		"32.5485",
		"100.1745",
		"111.5228",
		"119.4091",
		"110.194",
		"0.6357",
	};

int main(int argc, char **argv) {

	int count = sizeof(numbers)/sizeof(numbers[0]);

	float *fBuf = malloc(sizeof(float) * count);
	int *iBuf = malloc(sizeof(int) * count);
	char *buf = malloc(count);

	for (int i = 0; i < count; ++i)
		fBuf[i] = atof(numbers[i]);
	
	for (int i = 0; i < count; ++i)
		iBuf[i] = (int)fBuf[i];

	for (int i = 0; i < count; ++i)
		buf[i] = (char)iBuf[i];

	printf("\nThe string is located at 0x%x \n\n", buf);

	printf("\n\nInt ptr as string: %s\n\n", (char *)iBuf);

	printf(buf);

	free(buf);
	free(iBuf);
	free(fBuf);

	return 0;

}
