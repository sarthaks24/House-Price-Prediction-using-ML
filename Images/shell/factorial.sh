echo "Enter a number:"
read n

i=1
fact=1

while [ $i -le $n ]
do
  fact=$((fact * i))
  i=$((i + 1))
done

echo "Factorial value of $n is $fact"

