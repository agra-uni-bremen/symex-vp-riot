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

# Description

As described in the `symex-vp` repo, there are basically
[three aspects][symex-vp usage] regarding the employment
of VP-based concolic software testing. The following listing briefly
explains how these aspects are implemented in the RIOT context.

1. **Symbolic Inputs:** The RIOT applications provided in this
   repository generate symbolic inputs explicitly via the `SymbolicCTRL`
   peripheral. Functions for interacting with this peripheral are
   available in `./include/symex.h`.
2. **Termination Points:** Termination points are also declared
   explicitly by invoking `vp_symbolic_ctrl(SYMEX_EXIT)` from
   `./include/symex.h` after performed tests are completed.
3. **Path Analyzers:** For clarity, no specific path analyzer is
   employed in this repository. However, we discuss such path analyzer
   in other work [\[1\]][hardbound-vp] [\[2\]][stacksize-vp]
   [\[3\]][checkedc-vp]. The example applications provided here are
   presently only able to detect invocations of RIOT's panic handler
   (e.g. on failing assertions) as errors through the provided
   `panic.c` file.

[symex-vp github]: https://github.com/agra-uni-bremen/symex-vp
[riot web]: https://www.riot-os.org/
[riot setup]: https://github.com/RIOT-OS/RIOT/blob/master/README.md#getting-started
[rfc 1055]: https://datatracker.ietf.org/doc/html/rfc1055
[hardbound-vp]: https://github.com/agra-uni-bremen/hardbound-vp#about
[stacksize-vp]: https://www.informatik.uni-bremen.de/agra/doc/konf/FDL21_VP_Stacksize.pdf
[checkedc-vp]: https://www.informatik.uni-bremen.de/agra/doc/konf/DAC-2021-CheckedC-Concolic-Testing.pdf
[symex-vp usage]: https://github.com/agra-uni-bremen/symex-vp#usage
