for num in {1..50}
do
if [ $num -eq 1 ]; then
continue
fi
is_prime=true
for ((i=2; i*i<=num; i++))
do
if [ $((num % i )) -eq 0 ];
then
is_prime=false
break
fi
done
if $is_prime
then
echo $num
sum=$(($sum+$num))
fi
done
echo "Sum of primes from 1 to 50 is $sum"
