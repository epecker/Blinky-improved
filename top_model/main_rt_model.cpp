#include <cadmium/simulation/root_coordinator.hpp>

#ifndef NO_LOGGING
	#ifdef RT_ARM_MBED
//		#include <cadmium/simulation/logger/rt.hpp>
	#else
		#include <cadmium/simulation/logger/csv.hpp>
	#endif
#endif

#include <limits>
#include "blinkySystem.hpp"

#ifdef RT_ARM_MBED
	#include "../mbed.h"
#endif

using namespace cadmium::blinkySystem;

int main(int argc, char *argv[]) {

	auto model = std::make_shared<blinkySystem>("blinkySystem");
	auto rootCoordinator = cadmium::RootCoordinator(model);

#ifndef NO_LOGGING

	#ifdef RT_ARM_MBED
//		auto logger = std::make_shared<cadmium::RTLogger>(";");
	# else
		auto logger = std::make_shared<cadmium::CSVLogger>("blinkyLog.csv",";"); // new
	#endif
	rootCoordinator.setLogger<cadmium::Logger>(logger);
#endif

	rootCoordinator.start();
// 	rootCoordinator.simulate(std::numeric_limits<double>::infinity());
	rootCoordinator.simulate(1000.0);
	rootCoordinator.stop();
	return 0;
}
