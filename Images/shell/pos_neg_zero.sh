echo "Enter a number:"
read n
if [ $n -gt 0 ]
then
  echo "The given number $n is a positive number."
elif [ $n -lt 0 ]
then
  echo "The given number $n is a negative number."
else
  echo "The given number is zero."
fi

