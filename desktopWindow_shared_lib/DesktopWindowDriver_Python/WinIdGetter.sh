#!/bin/bash

# WinIdGetter.sh - by StephaneAG - 2013

#
#	Simple script allowing one to get a Window Id when passed a Window name
#	It uses 'xwininfo' and 'grep' internally to get Window infos & strip the irrelevant content from the output
#	The only output we should get is the actual corresponding Id
#

# useful RegEx for the Window Id ( wich seems to be an actual hexadecimal number )
WinIdRegEx='[0][x][0-9a-fA-F]{7}'

if (( $# != 0 )) # arguments were passed
 then
        # echo "The arguments passed were: $@ ."
        if [ "$1" = "-name" ]
         then
		if [ "$2" ]
		 then
                	# echo "CALLBACK_FROM_SCRIPT: bullshit !"
			script_return_value=`xwininfo -name "$2" | grep -Eho "$WinIdRegEx"` # should return the WinId corresponding to the Window name passed as argument
			echo "$script_return_value"
			#echo "Window name parameter: $2"
		else
			echo "Error: no Window name was passed as argument after the '-name' argument !"
		fi

        elif [ "$1" = "-h" ] || [ "$1" = "--help" ]
	 then
                 # echo "CALLBACK_FROM_SCRIPT: our precious !"
                script_return_value="Usage: WinIdGetter.sh -name <Window_name>" # echo usage
                echo "$script_return_value"
		# TO DO  execute a script with the right arguments and write the stuff returned to a specific file
        else
                echo "Error: unknown argument received"
        fi

 else
        echo "Error: no argument received"
fi

exit 0
