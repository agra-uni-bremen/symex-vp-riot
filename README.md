# symex-vp RIOT

Basic application illustrating use of [symex-vp][symex-vp github] with [RIOT][riot web].

# Usage

To build and use them follow the [instructions in the RIOT repository][riot-setup].
If all prerequisites are installed, application can simply be compiled
using:

	$ make -C <application>

Afterwards, a compiled application can be executed with `symex-vp`.
Assuming that `symex-vp` is in `$PATH`, simply run the following command
to execute one of the provided applications:

	$ make -C <application> simulate

# Symbolic Variables

The provided applications introduce symbolic variables explicitly
through the `SymbolicCTRL` peripheral. Functions for interacting with
this peripheral are available in `./include/symex.h`. Alternatively, it
is also possible to test RIOT applications through custom hardware
peripheral in provided in `symex-vp`. For example, it is possible to use
a [SLIP peripheral][RFC 1055] which returns symbolic network data to
explore the RIOT network stack.

[symex-vp github]: https://github.com/agra-uni-bremen/symex-vp
[riot web]: https://www.riot-os.org/
[riot setup]: https://github.com/RIOT-OS/RIOT/blob/master/README.md#getting-started
[rfc 1055]: https://datatracker.ietf.org/doc/html/rfc1055
