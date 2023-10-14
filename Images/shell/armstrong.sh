echo "Enter a number:"
read n

x=$n
sum=0

while [ $n -gt 0 ]
do
    y=`expr $n % 10`
    z=`expr $y \* $y \* $y`
    sum=`expr $sum + $z`
    n=`expr $n / 10`
done

if [ $x -eq $sum ]
then
    echo "$x is an Armstrong number."
else
    echo "$x is not an Armstrong number."
fi

