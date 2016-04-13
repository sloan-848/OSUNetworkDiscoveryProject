#!/bin/zsh
for i in `cat output.txt`
do
  echo 'Capturing' $i
  phantomjs rasterize.js http://$i ../captures/$i.png
done
