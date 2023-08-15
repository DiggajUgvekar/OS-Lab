echo "Enter the coefficients of the quadratic equation (a,b,c):"
read a
read b
read c

d=$((b*b - 4*a*c))

if [ $d -gt 0 ]
then
root1=$(echo "scale=2; (-$b + sqrt($d)) / (2*$a)" | bc)
root2=$(echo "scale=2; (-$b - sqrt($d)) / (2*$a)" | bc)
echo "Root 1: $root1"
echo "Root 2: $root2"
else 
if [ $d -eq 0 ]; then
    root1=$(echo "scale=2; -$b / (2*$a)" | bc)
    echo "Root: $root1"
else
    real=$(echo "scale=2; -$b / (2*$a)" | bc)
    imag=$(echo "scale=2; sqrt(-$d) / (2*$a)" | bc)
    echo "Root 1: $real + $imag i"
    echo "Root 2: $real - $imag i"
fi
fi

