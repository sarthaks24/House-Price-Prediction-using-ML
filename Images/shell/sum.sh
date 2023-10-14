

# Prompt the user to enter a number
echo "Enter a number: "
read n

# Initialize the sum variable to 0
sum=0

# Loop through all odd numbers up to n and add them to the sum
for (( i=1; i<=n; i+=2 ))
do
    sum=$((sum + i))
done

# Display the sum
echo "The sum of all odd numbers up to $n is: $sum"

