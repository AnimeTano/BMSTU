#!/bin/bash

if [ $# -ne 1 ]; then
echo "No processes sented or more than 1 process"
exit 1
fi

if ps aux | grep  "$1" > /dev/null; then
echo "Process '$1' started"
else
echo "Process '$1' don't found"
fi
