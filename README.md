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

	$ make -C <application> sim

[symex-vp github]: https://github.com/agra-uni-bremen/symex-vp
[riot web]: https://www.riot-os.org/
[riot setup]: https://github.com/RIOT-OS/RIOT/blob/master/README.md#getting-started
