# Introduction
These directories provide an API to open and close a u-blox device, i.e. a u-blox chip or module.  It is intended to be used in conjunction with the [common/network](/common/network) API; see the [README.md](/common/network)) there for usage information.

# Leaving Things Out
You will notice that there are `_stub.c` files in the [src](src) directory; if you are only interested in, say, cellular, and want to leave out short-range/GNSS functionality, you can simply replace, for instance, [u_device_private_short_range.c](src/u_device_private_short_range.c) with [u_device_private_short_range_stub.c](src/u_device_private_short_range_stub.c), etc. in your build metadata and your linker should then drop the unwanted things from your build.  You will need to do the same for the GNSS and Wi-Fi/BLE (i.e. short-range) components in [common/network/src](/common/network/src).