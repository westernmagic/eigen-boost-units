#pragma once
#include "BoostUnitsSupport.h"
#include <Eigen/Core>
#include <boost/units/quantity.hpp>
#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/area.hpp>
#include <boost/units/base_units/si/meter.hpp>
#include <boost/units/io.hpp>
#include <iostream>

namespace {
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
	using Area = quantity<area, double>;
	using Vector3A = Matrix<Area, 3, 1>;
}

