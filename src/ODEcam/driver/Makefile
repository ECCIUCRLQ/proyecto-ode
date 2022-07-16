# esta variable contiene el nombre de su driver compilado
BINARY     := odecam_module

# flags necesarios para compilar el driver 
KERNEL      := /lib/modules/$(shell uname -r)/build
ARCH        := x86
C_FLAGS     := -Wall
KMOD_DIR    := $(shell pwd)

# nuestro driver es odecam_driver.c
OBJECTS := odecam_driver.o

# todo lo demas queda como esta, no necesita cambios
ccflags-y += $(C_FLAGS)

obj-m += $(BINARY).o

$(BINARY)-y := $(OBJECTS)

$(BINARY).ko:
		make -C $(KERNEL) M=$(KMOD_DIR) modules

clean:
		rm -f $(BINARY).ko
		rm -f *.o *.cmd *.dwo *.mod *.mod.c *.order *.symvers 
