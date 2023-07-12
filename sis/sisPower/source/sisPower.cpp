
#include "sisPower.hpp"
#include <cstdlib>

void SisPower::shutdown() {
	std::system("awesomewm-client \"AwesomeWM.functions.shutdown()\"");
}

void SisPower::restart() {
	std::system("reboot");
}

void SisPower::lock() {
	std::system("betterlockscreen -l");
}

void SisPower::sleep() {
	std::system("systemctl suspend");
}

void SisPower::logout() {
	std::system("kill -9 -1");
}
