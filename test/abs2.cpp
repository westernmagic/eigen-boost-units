#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Length input = 1 * meter;
	Area result = 1 * meter * meter;

	assert(abs2(input) == result);
}

