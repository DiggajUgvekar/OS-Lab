echo "Enter number"
read n
if [ $n -eq 1 ]; then
echo "$n is not prime"
else
is_prime=true
for ((i=2; i*i<=n; i++))
do
if [ $((n % i )) -eq 0 ]  #checks if it contains factors
then
is_prime=false
echo "$n is not prime"
break
fi
done
if $is_prime
then
echo "$n is prime"
fi
fi
