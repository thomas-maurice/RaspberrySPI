#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <sys/types.h>
#include <linux/spi/spidev.h>
#include <errno.h>
#include <unistd.h>
#include <memory.h>

#include <SPI.hpp>
#include <SPI_MCP3208.hpp>

using namespace std;

int main(int argc, char ** argv) {
	SPI_MCP3208 port = SPI_MCP3208("/dev/spidev0.0", 1000000, SPI_MODE_0, 8);
	port.open_port();
    std::cout << port.readValue(true, 1) << std::endl;
	port.close_port();
	return EXIT_SUCCESS;
}
