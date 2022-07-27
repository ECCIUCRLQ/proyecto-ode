/* module_id.c - automatically generated, do not edit */

#include <simics/build-id.h>
#include <simics/base/types.h>
#include <simics/util/help-macros.h>

#if defined(SIMICS_6_API)
#define BUILD_API "6"
#elif defined(SIMICS_5_API)
#define BUILD_API "5"
#elif defined(SIMICS_4_8_API)
#define BUILD_API "4.8"
#else
#define BUILD_API "?"
#endif

#define EXTRA "                                           "

EXPORTED const char _module_capabilities_[] =
	"VER:" SYMBOL_TO_STRING(SIM_VERSION_COMPAT) ";"
	"ABI:" SYMBOL_TO_STRING(SIM_VERSION) ";"
	"API:" BUILD_API ";"
	"BLD:" "0" ";"
	"BLD_NS:__simics_project__;"
	"BUILDDATE:" "1657893078" ";"
	"MOD:" "odecam-pci-device" ";"
	"CLS:odecam_pci_device" ";"
	"HOSTTYPE:" "linux64" ";"
	"THREADSAFE;"
	EXTRA ";";
EXPORTED const char _module_date[] = "Fri Jul 15 14:51:18 2022";
extern void _initialize_odecam_pci_device_dml(void);
extern void init_local(void) {}
EXPORTED void _simics_module_init(void);
extern void sim_iface_wrap_init(void);

void
_simics_module_init(void)
{

	_initialize_odecam_pci_device_dml();
	init_local();
}
