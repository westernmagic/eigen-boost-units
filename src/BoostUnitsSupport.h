#include <boost/units/quantity.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/limits.hpp>
#include <boost/units/is_quantity.hpp>
#define EIGEN_MATRIXBASE_PLUGIN "MatrixBaseAddons.h"
#include <Eigen/Core>

namespace Eigen {
	using boost::units::quantity;
	using boost::units::multiply_typeof_helper;
	using boost::units::divide_typeof_helper;
	using boost::units::root_typeof_helper;
	using boost::units::static_rational;

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

	template<
		typename T1,
		typename T2
	>
	struct ScalarBinaryOpTraits<
		quantity<T1>,
		T2,
		internal::scalar_quotient_op<
			quantity<T1>,
			T2
		>
	> {
		typedef quantity<typename divide_typeof_helper<T1, T2>::type> ReturnType;
	};

	template<
		typename T1,
		typename T2
	>
	struct ScalarBinaryOpTraits<
		T1,
		quantity<T2>,
		internal::scalar_quotient_op<
			T1,
			quantity<T2>
		>
	> {
		typedef quantity<typename divide_typeof_helper<T1, T2>::type> ReturnType;
	};

	template<
		typename T1,
		typename T2
	>
	struct ScalarBinaryOpTraits<
		quantity<T1>,
		quantity<T2>,
		internal::scalar_quotient_op<
			quantity<T1>,
			quantity<T2>
		>
	> {
		typedef quantity<typename divide_typeof_helper<T1, T2>::type> ReturnType;
	};

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

			EIGEN_DEVICE_FUNC
			EIGEN_STRONG_INLINE const result_type operator() (const quantity<Unit, Scalar>& a) const {
				return numext::abs2(a);
			}

			template<typename Packet>
			EIGEN_DEVICE_FUNC EIGEN_STRONG_INLINE const Packet packetOp(const Packet& a) const
			{
				return internal::pmul(a,a);
			}
		};

		template<typename Unit, typename Scalar>
		struct abs2_retval<quantity<Unit, Scalar>> {
			typedef typename multiply_typeof_helper<
				quantity<Unit, Scalar>,
				quantity<Unit, Scalar>
			>::type type;
		};

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

template<
	typename Unit,
	typename Scalar
>
typename boost::units::multiply_typeof_helper<
	typename boost::units::quantity<Unit, Scalar>,
	typename boost::units::quantity<Unit, Scalar>
>::type abs2(const boost::units::quantity<Unit, Scalar> & x) {
	return x * x;
}


