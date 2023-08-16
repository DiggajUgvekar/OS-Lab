echo "Enter n"
read n
a=0
b=1
if [ $n -eq 1 ]
then
echo "Fibonnaci series : $a"
else
echo "Fibonnaci series : \n$a \n$b"
while [ $n -gt 2 ]
do
c=$(($a + $b))
echo "$c"
a=$b
b=$c
n=$((n-1))
done
fi
