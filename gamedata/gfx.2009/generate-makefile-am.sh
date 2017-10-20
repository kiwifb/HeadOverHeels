#!/bin/sh

printf "# "
echo "generated by" $0
echo

nameOfFolder="gamedatagfx2009"

echo "${nameOfFolder}dir = ""$""(""datadir"")""/""@""PACKAGE""@""/gfx.2009"

printf "${nameOfFolder}_DATA = "

listOfSubfolders="item.png gui.png blacktooth.png jail.png market.png themoon.png byblos.png egyptus.png penitentiary.png safari.png"
items=`find $listOfSubfolders -name "*.png" -type f -print`

howManyLines=`printf "${items}" | wc -l`
currentLine=0

echo "${items}" | while read line; do
        if [ $currentLine -gt 0 ]; then
                printf "\t\t\t"
        fi

        printf "%s" $line

        if [ $currentLine -lt $howManyLines ]; then
                printf " \\"
        fi
        echo

        currentLine=`expr $currentLine + 1`
done
