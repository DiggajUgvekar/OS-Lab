echo "Enter Length:"
read l

squ=$((l * l))
echo "Area of square is $squ"

echo "Enter Breadth:"
read b

rec=$((l * b))
echo "Area of rectangle is $rec"

echo "Enter Radius:"
read r

pi=3.14
cir=$(echo "$pi * $r * $r" | bc)
echo "Area of circle is $cir"
