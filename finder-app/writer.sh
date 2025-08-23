#!/bin/sh

# define variables for writefile and writestr
writefile=$1
writestr=$2

# error if first arg writefile, not provided
if [ -z "$writefile" ]
then
	echo "No file path provided, please provide file path as arg 1"
	exit 1
fi

# error if second arg writestr, not provided
if [ -z "$writestr" ]
then
	echo "No write string provided, please provide write string as arg 2"
	exit 1
fi

# make directory if it doesn't exist
mkdir -p "$(dirname "$writefile")"

# pass writestr into writefile, error if cannot write
if ! echo "$writestr" > "$writefile"
then
	echo "Could not write to $writefile"
	exit 1
fi


