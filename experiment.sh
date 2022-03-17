#!/bin/zsh
# Experiments for 3 DBSCAN iterations

if [ $1 == 'hepta' ]
then
    DATA_DIR="./dataset/fcps/hepta.csv"
    SIZE=212
    DIM=3
    MIN_SAMPLE=4
    EPS=0.75
elif [ $1 == 'lsun' ]
then
    DATA_DIR="./dataset/fcps/lsun.csv"
    SIZE=400
    DIM=2
    MIN_SAMPLE=4
    EPS=0.5
elif [ $1 == 'tetra' ]
then
    DATA_DIR="./dataset/fcps/tetra.csv"
    SIZE=400
    DIM=3
    MIN_SAMPLE=4
    EPS=0.4
elif [ $1 == 'target' ]
then
    DATA_DIR="./dataset/fcps/target.csv"
    SIZE=770
    DIM=2
    MIN_SAMPLE=4
    EPS=0.25
elif [ $1 == 'atom' ]
then
    DATA_DIR="./dataset/fcps/atom.csv"
    SIZE=800
    DIM=3
    MIN_SAMPLE=7
    EPS=15
elif [ $1 == 'twodiamonds' ]
then
    DATA_DIR="./dataset/fcps/twodiamonds.csv"
    SIZE=800
    DIM=2
    MIN_SAMPLE=50
    EPS=0.4
elif [ $1 == 'chainlink' ]
then
    DATA_DIR="./dataset/fcps/chainlink.csv"
    SIZE=1000
    DIM=3
    MIN_SAMPLE=4
    EPS=0.15
elif [ $1 == 'wingnut' ]
then
    DATA_DIR="./dataset/fcps/wingnut.csv"
    SIZE=1016
    DIM=2
    MIN_SAMPLE=4
    EPS=0.25
elif [ $1 == 'golfball' ]
then
    DATA_DIR="./dataset/fcps/golfball.csv"
    SIZE=4002
    DIM=3
    MIN_SAMPLE=4
    EPS=0.07
else
    echo "\nERROR: No dataset with given name\n"
    exit
fi

./dbscan-runs.sh original.cpp $DATA_DIR $SIZE $DIM $MIN_SAMPLE $EPS

./dbscan-runs.sh revised.cpp $DATA_DIR $SIZE $DIM $MIN_SAMPLE $EPS

./dbscan-runs.sh proposed.cpp $DATA_DIR $SIZE $DIM $MIN_SAMPLE $EPS
