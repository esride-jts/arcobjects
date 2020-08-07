// ao_engine.cpp : Defines the entry point for the application.
//

#include "ao_engine.h"

#include <pybind11/pybind11.h>

using namespace std;



void init()
{
}

void shutdown()
{
}



PYBIND11_MODULE(ao_engine, py_module) {
	py_module.doc() = "ArcObjects based geospatial engine.";

	py_module.def("init", &init, "Initializes the geospatial engine.");
	py_module.def("shutdown", &shutdown, "Shuts the geospatial engine down.");
}



int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
