#pragma once
#include <boost/units/quantity.hpp>
#include <boost/units/cmath.hpp>
#include <Eigen/Core>

namespace Eigen {
	using boost::units::quantity;
	using boost::units::root_typeof_helper;
	using boost::units::static_rational;

	namespace numext {
		template<typename Unit, typename Scalar>
		EIGEN_DEVICE_FUNC EIGEN_ALWAYS_INLINE
		typename root_typeof_helper<
			quantity<Unit, Scalar>,
			static_rational<2>
		>::type sqrt(const quantity<Unit, Scalar> &x) {
			using boost::units::sqrt;
			return sqrt(x);
		}
	} // namespace numext

	namespace internal {
		template<typename Unit, typename Scalar>
		struct scalar_sqrt_op<quantity<Unit, Scalar>> {
			EIGEN_EMPTY_STRUCT_CTOR(scalar_sqrt_op)
			typedef typename root_typeof_helper<
				quantity<Unit, Scalar>,
				static_rational<2>
			>::type result_type;

			EIGEN_DEVICE_FUNC inline const result_type operator() (const quantity<Unit, Scalar>& a) const {
				return numext::sqrt(a);
			}

			template <typename Packet>
			EIGEN_DEVICE_FUNC inline Packet packetOp(const Packet& a) const {
				return internal::psqrt(a);
			}
		};
	} // namespace internal
} // namespace Eigen

