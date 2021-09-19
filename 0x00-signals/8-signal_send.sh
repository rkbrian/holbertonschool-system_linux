#!/bin/sh
ARGC=$#
PID=$1
if [ $ARGC -ne 1 ]; then echo "Usage: $PID <pid>"
else kill -3 $PID; fi
