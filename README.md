# Project Structure:

```
.
├── a.out
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
├── dbscan-runs.sh
├── experiment.sh
├── include
│   └── dbscan.h
├── original.cpp
├── README.md
└── revised.cpp

3 directories, 19 files


```

# How to use：

```bash
chmod +x ./dbscan-runs.sh 
chmod +x ./experiment.sh  

bash experiment.sh 'hepta'
```
or
use GUI CLion
# Output:
```
./dataset/fcps/hepta.csv: DBSCAN in 0.016898 seconds.


./dataset/fcps/hepta.csv: Revised-DBSCAN in 0.018512 seconds.
```