sum=0
echo "The first five natural numbers:"
for i in 1 2 3 4 5
do
  sum=$((sum + i))
  echo $i
done
echo "The sum of first 5 natural numbers is $sum"

