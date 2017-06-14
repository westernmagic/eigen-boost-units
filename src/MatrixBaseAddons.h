template<typename T>
EIGEN_STRONG_INLINE
T squaredNorm() const {
	return numext::real((*this).cwiseAbs2().sum());
}

/*
template<
	typename T = typename std::enable_if<
		boost::units::is_quantity<typename internal::traits<Derived>::Scalar>::value,
		typename boost::units::multiply_typeof_helper<
			typename internal::traits<Derived>::Scalar,
			typename internal::traits<Derived>::Scalar
		>::type
	>::type
>
EIGEN_STRONG_INLINE
T squaredNorm() const {
	return numext::real((*this).cwiseAbs2().sum());
}
*/
