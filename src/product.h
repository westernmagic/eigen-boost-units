#pragma once
#include <boost/units/quantity.hpp>
#include <boost/units/cmath.hpp>
#include <Eigen/Core>

namespace Eigen {
	using boost::units::quantity;
	using boost::units::multiply_typeof_helper;

	template<
		typename T1,
		typename T2
	>
	struct ScalarBinaryOpTraits<
		quantity<T1>,
		T2,
		internal::scalar_product_op<
			quantity<T1>,
			T2
		>
	> {
		typedef quantity<typename multiply_typeof_helper<T1, T2>::type> ReturnType;
	};

	template<
		typename T1,
		typename T2
	>
	struct ScalarBinaryOpTraits<
		T1,
		quantity<T2>,
		internal::scalar_product_op<
			T1,
			quantity<T2>
		>
	> {
		typedef quantity<typename multiply_typeof_helper<T1, T2>::type> ReturnType;
	};

	template<
		typename T1,
		typename T2
	>
	struct ScalarBinaryOpTraits<
		T1,
		quantity<T2>,
		internal::scalar_product_op<
			quantity<T1>,
			quantity<T2>
		>
	> {
		typedef quantity<typename multiply_typeof_helper<T1, T2>::type> ReturnType;
	};
} // namespace Eigen

