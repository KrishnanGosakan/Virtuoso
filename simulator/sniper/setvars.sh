#!/bin/bash

# Include paths for Conda and your custom Sniper Sift simulator
export CPATH="/home/krishnan/TLB_loadbalancer/simulator/sniper/sift:$CONDA_PREFIX/include:$CPATH"
export C_INCLUDE_PATH=$CONDA_PREFIX/include:$C_INCLUDE_PATH
export CXX_INCLUDE_PATH=$CONDA_PREFIX/include:$CXX_INCLUDE_PATH

# Library paths for Conda
export LIBRARY_PATH=$CONDA_PREFIX/lib:$LIBRARY_PATH
export LD_LIBRARY_PATH=$CONDA_PREFIX/lib:$LD_LIBRARY_PATH
export LDFLAGS="-L$CONDA_PREFIX/lib $LDFLAGS"

