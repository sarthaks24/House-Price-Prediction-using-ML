echo "Enter a number:"
read n
r=$((n % 2))
if [ $r -eq 0 ]
then
  echo "The given number $n is even."
else
  echo "The given number $n is odd."
fi

