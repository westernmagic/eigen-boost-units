#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Vector3L input = {1 * meter, 1 * meter, 1 * meter};
	Vector3A result = {1 * meter * meter, 1 * meter * meter, 1 * meter * meter};

	assert(input.cwiseAbs2() == result);
}

