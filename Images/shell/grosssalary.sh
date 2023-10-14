echo "Enter the employee name:"
read name
echo "Enter the basic salary:"
read s
da=$(echo "scale=2; $s * 47 / 100" | bc)
hra=$(echo "scale=2; $s * 12 / 100" | bc)
cca=$(echo "scale=2; $s * 3 / 100" | bc)
gross=$(echo "scale=2; $s + $hra + $cca + $da" | bc)
echo "The gross salary of $name is $gross"
