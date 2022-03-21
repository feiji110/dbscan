# Project Structure

```
.
├── a.out
├── cmake-build-debug
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   │   ├── 3.16.5
│   │   │   ├── CMakeCCompiler.cmake
│   │   │   ├── CMakeCXXCompiler.cmake
│   │   │   ├── CMakeDetermineCompilerABI_C.bin
│   │   │   ├── CMakeDetermineCompilerABI_CXX.bin
│   │   │   ├── CMakeSystem.cmake
│   │   │   ├── CompilerIdC
│   │   │   │   ├── a.out
│   │   │   │   ├── CMakeCCompilerId.c
│   │   │   │   └── tmp
│   │   │   └── CompilerIdCXX
│   │   │       ├── a.out
│   │   │       ├── CMakeCXXCompilerId.cpp
│   │   │       └── tmp
│   │   ├── clion-environment.txt
│   │   ├── clion-log.txt
│   │   ├── cmake.check_cache
│   │   ├── CMakeDirectoryInformation.cmake
│   │   ├── CMakeOutput.log
│   │   ├── CMakeTmp
│   │   ├── dbscan.dir
│   │   │   ├── build.make
│   │   │   ├── cmake_clean.cmake
│   │   │   ├── CXX.includecache
│   │   │   ├── dbscan.cpp.o
│   │   │   ├── DependInfo.cmake
│   │   │   ├── depend.internal
│   │   │   ├── depend.make
│   │   │   ├── flags.make
│   │   │   ├── link.txt
│   │   │   ├── main.cpp.o
│   │   │   ├── original.cpp.o
│   │   │   ├── progress.make
│   │   │   ├── proposed.cpp.o
│   │   │   └── revised.cpp.o
│   │   ├── Makefile2
│   │   ├── Makefile.cmake
│   │   ├── progress.marks
│   │   └── TargetDirectories.txt
│   ├── cmake_install.cmake
│   ├── dbscan
│   ├── dbscan.cbp
│   └── Makefile
├── CMakeLists.txt
├── dataset
│   └── fcps
│       ├── atom.csv
│       ├── chainlink.csv
│       ├── engytime.csv
│       ├── golfball.csv
│       ├── hepta.csv
│       ├── lsun.csv
│       ├── target.csv
│       ├── tetra.csv
│       ├── twodiamonds.csv
│       └── wingnut.csv
├── dbscan.cpp
├── experiment.sh
├── include
│   ├── dbscan.h
│   └── nanoflann.hpp
├── original.cpp
├── README.md
└── revised.cpp

12 directories, 56 files
```

# How to use：
```bash
bash experiment.sh 'hepta'
```
or
use GUI CLion