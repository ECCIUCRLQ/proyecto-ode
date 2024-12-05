/*
  Camera user program.

  Authors:	David Sánchez
			Oscar Quesada
			Esteban Porras

  This is the user program that makes use of a driver
  that communicates with a virtual camera device called
  ODEcam and allows an user to simulate taking pictures
  and applying filters to them.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define CHARACTER_DEVICE_DRIVER_PATH "/dev/odecam_pci_device"
#define WR_VALUE _IOW('a','a',int32_t *)
#define RD_VALUE _IOR('b','b',int32_t *)
#define READ_VALUE_FROM_PCI_DEVICE _IOR('b', 'b', int32_t *)

int main()
{
    int fd;
    const char *chr_dev_name = CHARACTER_DEVICE_DRIVER_PATH;

    printf("*********************************\n");
    printf(">>> Opening ODEcam device\n");
    fd = open(chr_dev_name, O_RDWR);
    if (fd < 0) {
        printf("Cannot open ODEcam device file...\n");
        return 0;
    }
    printf("*********************************\n");

    int32_t camState =        0x18;
    int32_t filterVintage =   0x1C;
    int32_t filterBlur =      0x20;
    int32_t filterNegative =  0x24;
    int32_t filterBnW =       0x28;
    int32_t buffer =          0x2C;

    int32_t value = 0x1;
    ioctl(fd, WR_VALUE, (int32_t *) &value);
    printf("Powered ON device succesfully...\n");

    ioctl(fd, RD_VALUE, (int32_t*) &camState);
    printf("Read state register: 0x%x\n", camState);

    ioctl(fd, RD_VALUE, (int32_t*) &filterVintage);
    printf("Read vintage filter register: 0x%x\n", filterVintage);
    ioctl(fd, RD_VALUE, (int32_t*) &filterBlur);
    printf("Read blur filter register: 0x%x\n", filterBlur);
    ioctl(fd, RD_VALUE, (int32_t*) &filterNegative);
    printf("Read negative filter register: 0x%x\n", filterNegative);
    ioctl(fd, RD_VALUE, (int32_t*) &filterBnW);
    printf("Read black & white filter register: 0x%x\n", filterBnW);

    ioctl(fd, RD_VALUE, (int32_t*) &buffer);
    printf("Read buffer register: 0x%x\n", buffer);

    int32_t value = 0x0;
    ioctl(fd, WR_VALUE, (int32_t *) &value);
    printf("Powered OFF device succesfully...\n");

    printf("*********************************\n");
    printf(" >>> Closing ODEcam device\n");
    printf("*********************************\n");
    close(fd);
}
