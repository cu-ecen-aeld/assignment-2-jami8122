#!/bin/sh

# create variables for filedir searchstr
filedir=$1
searchstr=$2

#check if first arg is present
if [ -z "$filedir" ]
then
	echo "No file directory argument provided"
	exit 1
fi

#check if second arg is present
if [ -z "$searchstr" ]
then
	echo "No search string argument provided"
	exit 1
fi

#check if file path for filedir does not exist
if [ ! -d "$filedir" ]
then
	echo "$filedir does not exist, please input a valid filepath"
	exit 1
fi

#set x to num of files in $filedir
x=$(find "$filedir" -type f | wc -l)

#set y to num of matching lines for $searchstr in $filedir
y=$(grep -r "$searchstr" "$filedir" | wc -l)

echo "The number of files are $x and the number of matching lines are $y"


