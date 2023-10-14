echo "Enter the n value:"
read n

i=1
sum=0
j=0

until [ $i -gt $n ]
do
  echo "$i"
  sum=$((sum + i))
  j=$((j + 1))
  i=$((i + 2))
done

echo "The sum of the first $j odd numbers up to $n is $sum"

