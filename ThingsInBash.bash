n=10
if [ $n=10 ]
then 
	echo 'cool'
else
	echo 'strange'
fi


echo "enter your name"
read myname
echo "you entered: $myname"

echo "enter your name"
read myname mynam2
echo "you entered: $myname $mynam2"

 ls/root 2> errors.txt # samo greshkite otivat v tozi file


 myvar=1

while [ $myvar -le 10 ]
do
	echo $myvar
	myvar=$((myvar+1))
	sleep 0.5
done


PASSING AN ARGUMENT
echo $1 $2

or

args=("$@")

echo ${args[0]} ${args[1]} ${args[2]}

#echo $@

echo $#


#####################################
za zadachata
./a 4 5
echo $1 $2 -> 4 5
set ab bc cd
echo $1 $2 $3 -> ab bc cd


echo $1 $2 -> 4 5
set ab bc cd
echo $1 $2 $3 -> ab bc cd
shift
echo $1 $2 $3->bc cd

