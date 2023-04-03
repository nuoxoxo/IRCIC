#!/bin/bash

# L=$(basename "${BASH_SOURCE}"):0:3
# R=${L%\.*}

# L=$(ls)
# R=${L%\.*}

while :
do
	ls | sed "s/\.sh//g"
done
