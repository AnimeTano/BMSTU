#!/bin/bash 

if [ $# -ne 3 ]; then 
	echo "Use: $0 <directory> <host> <port>"
	exit 1
fi

dir = "$1"
host = "$2"
port = "$3"

mkdir -p "$dir"

for i in {1..5}; do
	filename = ""$dir"/file"$i".txt"
	echo "$i" > "$filename"
	echo "File created: $filename"
done

for file in "$dir"/*.txt; do
	echo "Sent $file"
	if nc "$host" "$port" < "$file"; then
		echo "File $file sented"
	else
		echo "Error"
		exit 1
	fi
done
