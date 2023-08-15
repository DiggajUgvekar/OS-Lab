directory="/home/diggaj/Desktop/Codes/Diggaj/Expt2"
count=$(ls -l $directory| grep ^- | wc -l)
echo "number of files in directory : $count"
