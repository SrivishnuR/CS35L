#!/bin/bash

filename=commands.txt

while read -r line 
do
ldd "/usr/bin/$line" | sed '/not a dynamic executable/d' | sed 's/(.*)$//g' 
done < $filename