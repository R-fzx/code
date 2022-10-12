#!/bin/sh
#A simple tester by wym510
#ver 1.0.0

echo "input the mainname"
read mainname

inputf=${mainname}.in
outputf=${mainname}.out

echo ${mainname} > ${mainname}.log
for i in $(seq 0 99)
do
    cp ${mainname}$i.in $inputf -f
    echo "${i}:"
    time ./${mainname}
    echo ""
    diff ${mainname}$i.out $outputf -w

    if [ $? -ne 0 ]; then
        echo "${i}: WA" >> ${mainname}.log
    else
        echo "${i}: AC" >> ${mainname}.log
    fi 
done
rm $inputf
rm $outputf
cat ${mainname}.log
