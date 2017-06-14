find_package (Eigen3 3.3 REQUIRED NO_MODULE)
find_package (Boost REQUIRED)

foreach (i abs2 cwiseMin cwiseMax cwiseAbs2 cwiseAbs cwiseSqrt cwiseInverse cwiseProduct cwiseQuotient cwiseEqual cwiseNotEqual norm squaredNorm sum difference scalar_product scalar_quotient)
	add_executable (test_${i} ${i}.cpp)
	target_link_libraries (test_${i} Eigen3::Eigen Boost::boost)
	add_test (NAME ${i} COMMAND ${CMAKE_COMMAND} --build . --target test_${i})
endforeach (i)
