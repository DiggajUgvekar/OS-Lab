ch=1
while [ $ch -eq 1 ]
do
echo "\nMenu\n"
echo "1)Display present working directory\n2)Display users of the system\n3)Display calender of a year\n"
echo "Enter you choice "
read choice
case $choice in
1)echo $(pwd)
;;
2)echo $(who)
;;
3)echo "Enter the year"
read year
echo "\n"
echo $(cal $year)
;;
*)echo "Invaild Choice"
esac
echo "Do you want to continue(0 or 1)"
read ch
done
