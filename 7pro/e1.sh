echo "Enter a num"
read n
l=$(($n % 2))
if [ $l -eq 0 ]
then
echo "$n is even"
else
echo "$n is odd"
fi
