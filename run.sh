filename=$*

rm -f output

g++ -Wall -std=c++20 -g -o output $filename

./output
rm output