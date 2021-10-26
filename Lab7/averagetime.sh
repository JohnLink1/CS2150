#!/bin/bash

RUNC=5
#get dictionary and grid filenames
read ITR

if [[ $ITR == "quit" ]] ; then
	exit
fi

while [[ $RUNC != 0 ]] ; do
	RUN=`./a.out $ITR | tail -1`
	((SUM = SUM + RUN))
	((RUNC = RUNC - 1))
done

echo $((SUM / 5))
