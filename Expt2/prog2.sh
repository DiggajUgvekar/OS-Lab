directory="/home/fundlab9/Desktop/Diggaj/codes/Expt2"
count=$(ls -l $directory| grep ^- | wc -l)
echo "number of files in directory : $count"
