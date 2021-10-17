#!/bin/bash

#get dictionary and grid filenames
read DICT GRID

#Get time taken and only record the last line
RUN1=`./a.out $DICT $GRID | tail -1`

#Get time taken and only record the last line
RUN2=`./a.out $DICT $GRID | tail -1`

#Get time taken and only record the last line
RUN3=`./a.out $DICT $GRID | tail -1`

#Get time taken and only record the last line
RUN4=`./a.out $DICT $GRID | tail -1`

#Get time taken and only record the last line
RUN5=`./a.out $DICT $GRID | tail -1`

#Sum up all times
SUM=`bc <<<"scale=3 ; $RUN1 + $RUN2 + $RUN3 + $RUN4 + $RUN5"`

#print out average time
echo `bc <<<"scale=3 ; $SUM / 5"`
