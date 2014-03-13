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

using namespace std;

int main(int argc, char ** argv) {
	SPI port = SPI("/dev/spidev0.0", 250000, SPI_MODE_0, 8);

	port.open_port();
	
    unsigned char commande[4];
    memset(commande, 0, 4);
    
    commande[0] = 0x03;
    commande[1] = 0x04;
    commande[2] = 0x0c;
    commande[3] = 0x0d;
	
	cout << "Avant envoi:";
	
    for(unsigned int i = 0; i < 10; i++) {
		printf(" 0x%02x", commande[i]);
	}
	
	cout<<endl;

	port.transfer(commande, 4);
	
	cout << "Après envoi:";
	for(unsigned int i = 0; i < 10; i++) {
		printf(" 0x%02x", commande[i]);
	}
	
	cout<<endl;
	
	cout << "Ok, closing the bus" << endl;

	port.close_port();

	return EXIT_SUCCESS;
}
