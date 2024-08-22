#! /bin/bash
cat /etc/passwd | sed '/^\s*#/d' | awk -F":" 'NR%2==0 { print $1 }' | rev | sort -r | awk "$FT_LINE1<=NR && NR<=$FT_LINE2" | sed -z 's/\
n/, /g' | sed -E 's/, $/\n/'

