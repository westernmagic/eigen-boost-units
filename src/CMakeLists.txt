#find_package (Eigen3 3.3 REQUIRED NO_MODULE)
find_package (Boost REQUIRED)

include_directories (.)
add_executable (eigen_boost eigen_boost.cpp)
target_link_libraries (eigen_boost Eigen Boost::boost)

