#!/bin/sh
#Created on 15:30:48 2016-06-22
#@author: heshenghuan (heshenghuan@sina.com)
#http://github.com/heshenghuan

easy=`cat README.md | grep Easy | wc -l`
medium=`cat README.md | grep Medium | wc -l`
hard=`cat README.md | grep Hard | wc -l`
sum=$((easy+medium+hard))
date=`date`

cpp=`cat README.md | grep C++ | wc -l`
sh=`cat README.md | grep Shell | wc -l`
py=`cat README.md | grep Python | wc -l`
js=`cat README.md | grep JavaScript | wc -l`
java=`cat README.md | grep Java | wc -l`


echo $date
printf "========================================\n"
printf "Statistics of Solutions:\n"
printf "Total                 %3d\n" $sum
printf "Easy solutions:       %3d\t%2.2f%%\n" $easy $((easy*100/sum))
printf "Medium solutions:     %3d\t%2.2f%%\n" $medium $((medium*100/sum))
printf "Hard solutions:       %3d\t%2.2f%%\n" $hard $((hard*100/sum))
printf "========================================\n"
printf "C++ solutions:        %3d\t%2.2f%%\n" $cpp $((cpp*100/sum))
printf "Java solutions:       %3d\t%2.2f%%\n" $java $((java*100/sum))
printf "Shell solutions:      %3d\t%2.2f%%\n" $sh $((sh*100/sum))
printf "Python solutions:     %3d\t%2.2f%%\n" $py $((py*100/sum))
printf "JavaScript solutions: %3d\t%2.2f%%\n" $js $((js*100/sum))
printf "========================================\n"


echo "\n\n"$date >> statis.log
printf "========================================\n" >> statis.log
printf "Statistics of Solutions:\n" >> statis.log
printf "Total                 %3d\n" $sum >> statis.log
printf "Easy solutions:       %3d\t%2.2f%%\n" $easy $((easy*100/sum)) >> statis.log
printf "Medium solutions:     %3d\t%2.2f%%\n" $medium $((medium*100/sum)) >> statis.log
printf "Hard solutions:       %3d\t%2.2f%%\n" $hard $((hard*100/sum)) >> statis.log
printf "========================================\n" >> statis.log
printf "C++ solutions:        %3d\t%2.2f%%\n" $cpp $((cpp*100/sum)) >> statis.log
printf "Java solutions:       %3d\t%2.2f%%\n" $java $((java*100/sum)) >> statis.log
printf "Shell solutions:      %3d\t%2.2f%%\n" $sh $((sh*100/sum)) >> statis.log
printf "Python solutions:     %3d\t%2.2f%%\n" $py $((py*100/sum)) >> statis.log
printf "JavaScript solutions: %3d\t%2.2f%%\n" $js $((js*100/sum)) >> statis.log
printf "========================================\n" >> statis.log
