arr=($@)
for((i=1;i<n;i++))
do
	j=$i-1
	echo $j
	echo "this"
	temp=${arr[$i]}
	while((j>=0 && arr[j]>temp))
	do
		arr[$j+1]=${arr[$j]}
		j=$j-1
	done
	arr[j+1]=$temp
done
echo ${arr[@]}