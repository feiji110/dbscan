#!/bin/zsh
# DBSCAN runs

# g++ $1 dbscan.cpp && ./a.out dataset/fcps/hepta.csv 212 3 4 0.75
# g++ $1 dbscan.cpp && ./a.out dataset/fcps/lsun.csv 400 2 4 0.5
# g++ $1 dbscan.cpp && ./a.out dataset/fcps/tetra.csv 400 3 4 0.4
# g++ $1 dbscan.cpp && ./a.out dataset/fcps/target.csv 770 2 4 0.25
# g++ $1 dbscan.cpp && ./a.out dataset/fcps/atom.csv 800 3 7 15
# g++ $1 dbscan.cpp && ./a.out dataset/fcps/twodiamonds.csv 800 2 50 0.4
# g++ $1 dbscan.cpp && ./a.out dataset/fcps/chainlink.csv 1000 3 4 0.15
# g++ $1 dbscan.cpp && ./a.out dataset/fcps/wingnut.csv 1016 2 4 0.25
# g++ $1 dbscan.cpp && ./a.out dataset/fcps/golfball.csv 4002 3 4 0.07
g++ $1 dbscan.cpp && ./a.out $2 $3 $4 $5 $6

# next, collect the twitter subset datasets
# run the 3 dbscan impls and collect the result
# run the experiments on 100-server
