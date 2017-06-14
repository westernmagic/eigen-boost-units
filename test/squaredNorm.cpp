#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Vector3L input = {1 * meter, 1 * meter, 1 * meter};
	Area result = 3 * meter * meter;

	assert(input.squaredNorm() == result);
}

