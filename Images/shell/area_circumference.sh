echo "Enter the radius:"
read r
area=$(echo "scale=2; 22/7 * $r * $r" | bc)
circumference=$(echo "scale=2; 2 * 22/7 * $r" | bc)
echo "Area = $area"
echo "Circumference = $circumference"

