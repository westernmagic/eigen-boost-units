#pragma once
#include <boost/units/quantity.hpp>
#include <boost/units/cmath.hpp>
#include <Eigen/Core>

template<
	typename Unit,
	typename Scalar
>
typename boost::units::multiply_typeof_helper<
	boost::units::quantity<Unit, Scalar>,
	boost::units::quantity<Unit, Scalar>
>::type abs2(const boost::units::quantity<Unit, Scalar> & x) {
	return x * x;
}

namespace Eigen {
	using boost::units::quantity;
	using boost::units::multiply_typeof_helper;

	namespace numext {
		template<
			typename Unit,
			typename Scalar
		>
		typename multiply_typeof_helper<
			quantity<Unit, Scalar>,
			quantity<Unit, Scalar>
		>::type abs2(const quantity<Unit, Scalar> & x) {
			using ::abs2;
			return abs2(x);
		}
	} //namespace numext

	namespace internal {
		template<
			typename Unit,
			typename Scalar
		>
		struct abs2_impl<quantity<Unit, Scalar>> {
			EIGEN_DEVICE_FUNC
			static inline typename multiply_typeof_helper<
				quantity<Unit, Scalar>,
				quantity<Unit, Scalar>
			>::type run(const quantity<Unit, Scalar>& x) {
				return x * x;
			}
		};

		template<
			typename Unit,
			typename Scalar
		>
		struct scalar_abs2_op<quantity<Unit, Scalar>> {
			EIGEN_EMPTY_STRUCT_CTOR(scalar_abs2_op)
			typedef typename multiply_typeof_helper<
				quantity<Unit, Scalar>,
				quantity<Unit, Scalar>
			>::type result_type;

			EIGEN_DEVICE_FUNC EIGEN_STRONG_INLINE
			const result_type operator() (const quantity<Unit, Scalar>& a) const {
				return numext::abs2(a);
			}

			template<typename Packet>
			EIGEN_DEVICE_FUNC EIGEN_STRONG_INLINE
			const Packet packetOp(const Packet& a) const {
				return internal::pmul(a,a);
			}
		};
	} // namespace internal
} // namespace Eigen

