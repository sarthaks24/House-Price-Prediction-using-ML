echo "Enter two numbers:"
read a b
big=$a
if [ $b -gt $big ]
then
  big=$b
fi
echo "$big is the greatest"
