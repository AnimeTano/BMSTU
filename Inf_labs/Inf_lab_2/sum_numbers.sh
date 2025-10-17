#!/bin/bash

if [ $# -ne 2 ]; then
echo "Please, enter 2 numbers:"
exit 1
fi

result=$(expr $1 + $2)
echo $result
