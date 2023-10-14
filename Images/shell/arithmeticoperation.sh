echo "Enter the two numbers:"
read a b
echo "Menu
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit"

echo "Enter your choice:"
read choice
case $choice in
  1)
    sum=$((a + b))
    echo "The sum of $a and $b is $sum"
    ;;
  2)
    difference=$((a - b))
    echo "The difference of $a and $b is $difference"
    ;;
  3)
    product=$((a * b))
    echo "The product of $a and $b is $product"
    ;;
  4)
    quotient=$((a / b))
    echo "The quotient when $a is divided by $b is $quotient"
    ;;
  5)
    echo "Bye!"
    exit
    ;;
  *)
    echo "Invalid choice!"
    ;;
esac

