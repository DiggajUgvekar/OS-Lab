echo "Enter no. of processes : "
read n
echo "Enter Burst time of $n processes"
for((c=0;c<$n;c++))
do
read bt[$c]
done

#waiting time
wt[0]=0;
for((i=1;i<$n;i++))
do
wt[$i]=`expr ${bt[$i-1]} + ${wt[$i-1]}`
wsum=$((wsum+wt[$i]))
done

avg1=$(echo "scale=2; ($wsum) / ($n)" | bc)
echo "Waiting time"
echo "${wt[@]}"
echo "Average Waiting time"
echo "$avg1"

#turn around time
for((i=0;i<n;i++))
do
tat[$i]=`expr ${bt[$i]} + ${wt[$i]}`;
tsum=$((tsum+tat[$i]))
done

avg2=$(echo "scale=2; ($tsum) / ($n)" | bc)
echo "Turn around time"
echo "${tat[@]}"
echo "Average Turn around time"
echo "$avg2"

echo "Gantt Chart"
for((i=0;i<$n;i++))
do
printf "${wt[$i]}\t"
done
printf "\n"
