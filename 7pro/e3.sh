echo "Enter n"
read n
sum=0
avg=0
n1=$n
while [ $n -gt 0 ]
do
echo "Enter element : "
read elem
sum=$(($sum + $elem))
n=$(($n-1))
done
ave=$(($sum / $n1))
echo "Sum is $sum"
echo "Average is $ave"
