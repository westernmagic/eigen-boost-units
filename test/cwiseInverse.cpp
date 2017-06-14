#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Vector3L input = {1 * meter, 1 * meter, 1 * meter};
	Vector3L result = {1 * meter, 1 * meter, 1 * meter};

	assert(input.cwiseInverse() == result);
}

