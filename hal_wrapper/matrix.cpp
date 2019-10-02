#include <pybind11/pybind11.h>
#include "./matrix.h"
#include "./drivers/sensors.h"
#include "./drivers/everloop.h"

// Declare bus for MATRIX hardware communication
matrix_hal::MatrixIOBus bus;

// Initialize MATRIX bus
bool busReady = bus.Init();

// Exported Python module
namespace py = pybind11;
PYBIND11_MODULE(matrix_hal, m) {
    m.doc() = R"pbdoc(Docs coming soon)pbdoc";
    init_sensors(m);
    init_led(m);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}