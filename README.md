Java Syzygy Bridge
==================
To be able to use Ronald de Man's Syzygy tablebases in a Java program I have modified the Fathom programming API to allow for execution via JNI.

Companion to this C/C++ code is a java jar file that mirrors the functionality of the programming API as explained below.
This jar file can be included in any java chess engine and takes care of the loading the libJSyzygy.so library.
All functionality in the jar file is located in the SyzygyBridge class in the form of six static functions.
In addition to the `probeSyzygyWDL` and `probeSyzygyWDL` functions there are some support functions: 
* `isLibLoaded` (determine if the libJSyzygy.so library was succesfully loaded)
* `load` (loads the tablebases)
* `isAvailable` (determine if the tablebases for the specified size are loaded)
* `getSupportedSize` (returns TB_LARGEST from tbprobe.h)

The SyzygyConstants class contains the various constants normally exposed by the tbprobe.h header file.

Platforms
---------
This Java Syzygy Bridge was developed on linux. No effort was yet invested to get it to work on any other machine than my own.
To compile this software a java 8 JDK is needed. The following command was used on my machine:
`g++ -std=c++14 -O2 -Wall -D TB_USE_ATOMIC -D TB_NO_HW_POP_COUNT -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -shared -o libJSyzygy.so tbprobe.c`

Credits
-------
* Syzygy Tablebases were conceived by Ronald de Man (https://github.com/syzygy1/tb).
* Fathom was developed by basil00 (https://github.com/basil00/Fathom).
* My modifications are based on the Jon Dart fork (https://github.com/jdart1/Fathom)


Original Fathom
===============

Fathom is a stand-alone Syzygy tablebase probing tool. The aims of Fathom are:

* To make it easy to integrate the Syzygy tablebases into existing chess
  engines;
* To make it easy to create stand-alone applications that use the Syzygy
  tablebases;

Tool
----

The actual Fathom tool is excluded from this fork because it is not needed in any way for the purpose of a Java Syzygy Bridge.

Programming API
---------------

Fathom provides a simple API. There are three main function calls:

* `tb_init` initializes the tablebase
* `tb_probe_wdl` probes the Win-Draw-Loss (WDL) table for a given position
* `tb_probe_root` probes the Distance-To-Zero (DTZ) table for the given
  position.

All of the API functions use basic integer types, i.e. there is no need to
create and initialize data-structures. Fathom does not require the callee
to provide any additional functionality (e.g. move generation) unlike the
traditional `tbprobe` code. However, chess engines can opt to replace some
of the functionality of Fathom for better performance (see below).

Chess Engines
-------------

Chess engines can be `tb_probe_wdl` to get the WDL value during search. The
`tb_probe_root` functional can be used to help pick the best move at the root.
Note that `tb_probe_root` is slower and therefore should only be used at the
root.

Chess engines can opt for a tighter integration of Fathom by configuring
`tbconfig.h`. Specifically, the chess engines can define `TB_*_ATTACKS`
macros that replace the default definitions with the engine's own definitions,
avoiding duplication of functionality.

Credits
-------

The Syzygy tablebases were created by Ronald de Man. Much of the probing code
`tbprobe.c` is a modified version of Ronald's `tbprobe.cpp` for Stockfish (all
Stockfish-specific code has been removed). The `tbcore.c` file is virtually
unchanged from Ronald's original version.

License
-------

(C) 2013-2015 Ronald de Man (original code)
(C) 2015 basil (new modifications)

Ronald de Man's original code can be "redistributed and/or modified without
restrictions".

The new modifications are released under the permissive MIT License:

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

