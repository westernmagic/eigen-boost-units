#include "BoostUnitsSupport.h"
#include <Eigen/Core>
#include <boost/units/quantity.hpp>
#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/area.hpp>
#include <boost/units/base_units/si/meter.hpp>
#include <boost/units/io.hpp>
#include <iostream>

int main(int /*argc*/, char** /*argv*/) {
	using std::cout;
	using Eigen::Matrix;
	using boost::units::quantity;
	using boost::units::make_system;
	using boost::units::unit;
	using boost::units::length_dimension;
	using boost::units::area_dimension;
	using boost::units::si::meter_base_unit;
	using system = make_system<meter_base_unit>::type;
	using length = unit<length_dimension, system>;
	static const length meter;
	using area = unit<area_dimension, system>;

	using Length = quantity<length, double>;
	using Vector3L = Matrix<Length, 3, 1>;

	Length l = 1 * meter;
	Vector3L x = {l, l, l};

	abs2(l);

	using Area = quantity<area, double>;
	using Vector3A = Matrix<Area, 3, 1>;

	Vector3A a = x.cwiseAbs2();
	//Area x2 = x.squaredNorm<>();
}

