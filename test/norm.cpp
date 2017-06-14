#include "test.h"

int main(int /*argc*/, char** /*argv*/) {
	Vector3L input = {1 * meter, 1 * meter, 1 * meter};
	Length result = std::sqrt(3) * meter;

	assert(input.norm() == result);
}

