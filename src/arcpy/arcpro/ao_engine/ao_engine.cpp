// ao_engine.cpp : Defines the entry point for the application.
//

#include "ao_engine.h"

#include <pybind11/pybind11.h>

#include <comutil.h>

using namespace std;

int init_engine(const string& version)
{
	::CoInitialize(NULL);

	ArcGISVersionLib::IArcGISVersionPtr version_instance(__uuidof(ArcGISVersionLib::VersionManager));
	if (!version_instance)
	{
		return -1;
	}

	VARIANT_BOOL version_loaded(VARIANT_FALSE);

	CComBSTR bstr_version(_com_util::ConvertStringToBSTR(version.c_str()));
	if (FAILED(version_instance->LoadVersion(ArcGISVersionLib::esriArcGISDesktop, bstr_version, &version_loaded)))
	{
		return -2;
	}
	if (VARIANT_FALSE == version_loaded)
	{
		return -3;
	}

	return 0;
}

void shutdown_engine()
{
	::CoUninitialize();
}



PYBIND11_MODULE(ao_engine, py_module) {
	py_module.doc() = "ArcObjects based geospatial engine.";

	py_module.def("init", &init_engine, "Initializes the geospatial engine.");
	py_module.def("shutdown", &shutdown_engine, "Shuts the geospatial engine down.");
}



int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
