#!/bin/bash

if [ $# -ne 1 ]; then
echo "Enter name of process:"
exit 1
fi

if pgrep -x  "$name" > /dev/null; then
echo "Process '$name started'"
else
echo "Process don't found"
fi
