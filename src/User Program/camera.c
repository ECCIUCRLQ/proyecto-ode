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

#include <iostream>

#define WR_VALUE _IOW('a', 'a', int32_t *)
#define RD_VALUE _IOR('b', 'b', int32_t *)
#define READ_VALUE_FROM_PCI_DEVICE _IOR('b', 'b', int32_t *)

int main(){

    return 0;
}

