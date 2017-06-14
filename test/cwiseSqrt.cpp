#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Vector3A input = {1 * meter * meter, 1 * meter * meter, 1 * meter * meter};
	Vector3L result = {1 * meter, 1 * meter, 1 * meter};

	assert(input.cwiseSqrt() == result);
}

