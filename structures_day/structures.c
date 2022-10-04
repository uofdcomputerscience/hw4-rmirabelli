#include "s_impl.h"

int main(int argc, char **argv) {

	WavePoint wp;

	wp.frequency.iValue = 42;
	wp.amplitude.fValue = 5.0;

	printWavePoint(&wp);

	return 0;

}
