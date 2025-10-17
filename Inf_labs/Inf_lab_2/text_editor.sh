#!/bin/bash
touch notes.txt

while true; do
	read name
	if [ "$name" != "exit" ]; then
	    echo "$name" >>  notes.txt
	else
	    break
	fi
done

echo "----------"
cat notes.txt
echo "----------"

rm notes.txt
