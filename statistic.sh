#!/bin/sh
#Created on 15:30:48 2016-06-22
#@author: heshenghuan (heshenghuan@sina.com)
#http://github.com/heshenghuan

easy=`cat README.md | grep Easy | wc -l`
medium=`cat README.md | grep Medium | wc -l`
hard=`cat README.md | grep Hard | wc -l`
sum=$((easy+medium+hard))

printf "Statistics of Solutions:\n"
printf "======================================\n"
printf "Total             %d\n" $sum
printf "Easy solutions:   %d\t%2.2f%%\n" $easy $((easy*100/sum))
printf "Medium solutions: %d\t%2.2f%%\n" $medium $((medium*100/sum))
printf "Hard solutions:   %d\t%2.2f%%\n" $hard $((hard*100/sum))
printf "======================================\n"
