if tty -s
then
	export NORMAL=$(tput sgr0)
	export RED=$(tput setaf 1)
	export GREEN=$(tput setaf 2)
	export YELLOW=$(tput setaf 3)
	export BLUE=$(tput setaf 4)
fi

ERROR="0"

function compilation_and_run {
	tty -s && tput sc # save context

	myfile="${1}/our.log"
	hisfile="${1}/his.log"
	compil_out="${1}/compilation.log"
	difflog="${1}/diff.log"

	rm -f $myfile $hisfile

	for file in ${1}/*_our.cpp
	do
		echo ${YELLOW}$file${NORMAL}
		clang++ -Wextra -Werror -Wall $file 2> $compil_out
		if [[ $? != "0" ]]
		then
			echo ❌${RED} Compilation error: ${NORMAL}$file 
			return 1
		fi
		./a.out >> $myfile
	done

	for file in ${1}/*_his.cpp
	do
		clang++ -Wextra -Werror -Wall $file 2> $compil_out
		if [[ $? != "0" ]]
		then
			echo ❌${RED} Compilation error: ${NORMAL}$file 
			return 1
		fi
		./a.out >> $hisfile
	done

	tty -s && tput rc && tput ed # restore context
	rm -f a.out $compil_out
	diff $myfile $hisfile > $difflog
	return $?
}

function run_from_here {
	directory=$1
	stat $directory 2> /dev/null > /dev/null
	if [[ $? != "0" ]]
	then
		echo "❌ ${RED} Ce test n'existe pas !${NORMAL}"
		exit 1
	fi
	compilation_and_run $directory
	if [[ $? != "0" ]]
	then
		ERROR="1"
		echo -n "${RED} ❌ "
		echo $directory | sed "s/tests\///g"
		echo -n $NORMAL
		echo "${BLUE}Additionnal logs:"
		for log_file in $directory/*.log
		do
			echo "${log_file}"
		done
	else
		echo -n "${GREEN} ✅ "
		echo $directory | sed "s/tests\///g"
		echo -n $NORMAL
	fi
}

stat .git 2> /dev/null > /dev/null
if [[ $? != "0" ]]
then
	echo " ❌ ${RED} Vous devez appeller ce script a la racine de votre projet${NORMAL}"
	exit 1
fi

if [[ $1 ]]
then
	run_from_here "tests/test_"$1
	exit $ERROR 
fi

for folder in tests/test_*
do
	run_from_here $folder
done

exit $ERROR