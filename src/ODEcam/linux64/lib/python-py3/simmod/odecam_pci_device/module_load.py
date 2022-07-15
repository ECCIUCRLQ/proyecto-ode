# This Software is part of Simics. The rights to copy, distribute,
# modify, or otherwise make use of this Software may be licensed only
# pursuant to the terms of an applicable license agreement.
# 
# Copyright 2010-2022 Intel Corporation

import cli
import pci_common

cli.new_info_command("sample_pci_device", pci_common.get_pci_info)
cli.new_status_command("sample_pci_device", pci_common.get_pci_status)
pci_common.new_pci_config_regs_command('sample_pci_device', None)
