echo "Enter the n value:"
read n

i=2
sum=0
j=0

while [ $i -le $n ]
do
  echo "$i"
  sum=$((sum + i))
  j=$((j + 1))
  i=$((i + 2))
done

echo "The sum of the first $j even numbers up to $n is $sum"

