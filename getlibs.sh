#!/bin/bash
filename='libs.txt'
while read line; do

# reading each line
arrLine=(${line//// })
libPath="./libs/${arrLine[-1]}"
wget -O $libPath ${line}
tar xf $libPath -C ./libs
rm $libPath

done < $filename