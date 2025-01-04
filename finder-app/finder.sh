#!/bin/sh


if [ $# -eq 0 ]
then
	echo "No parameters specified, 2 required"
	exit 1
fi

if [ ! -d $1 ]
then
	echo "The first parameter shall be a directory"
	exit 1
fi

FILES_DIR=$1
SEARCH_STR=$2
IFS='
'

FILES="$(find ${FILES_DIR} -type f)"
FILES_NUM=0
for FILE in $FILES
do
	FILES_NUM=$((FILES_NUM+1))
done

cd ${FILES_DIR}

LINES="$(grep -r "${SEARCH_STR}" *)"
LINES_NUM=0
for LINE in $LINES
do
	LINES_NUM=$((LINES_NUM+1))
done

echo "The number of files are ${FILES_NUM} and the number of matching lines are ${LINES_NUM}"
exit 0

