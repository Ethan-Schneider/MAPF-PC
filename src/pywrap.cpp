// pywrap.cpp
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#include "pbs.cpp"

namespace py = pybind11;
constexpr auto byref = py::return_value_policy::reference_internal;

PYBIND11_MODULE(mgpbs, m) {
    m.doc() = "optional module docstring";
    m.def("test_cpp_func", &pymain, "A function");
}
