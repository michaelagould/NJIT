#!/bin/bash

if [ $1 -gt 100 ]
then
    echo That is a large number.
fi

# ! EXPRESSION              ! EXPRESSION
# -n STRING                 strlen(STRING) != 0
# -z STRING                 strlen(STRING) == 0
# STRING1 = STRING2         STRING1 == STRING2
# STRING1 != STRING2        STRING1 != STRING2
# INTEGER1 -eq INTEGER2     INTEGER1 == INTEGER2
# INTEGER1 -ge INTEGER2     INTEGER1 >= INTEGER2
# INTEGER1 -gt INTEGER2     INTEGER1 > INTEGER2
# INTEGER1 -le INTEGER2     INTEGER1 <= INTEGER2
# INTEGER1 -lt INTEGER2     INTEGER1 < INTEGER2
# INTEGER1 -ne INTEGER2     INTEGER1 != INTEGER2
# -d FILE                   FILE exists and is a directory.
# -e FILE                   FILE exists.
# -s FILE                   FILE exists and is not empty.
# -r FILE                   FILE exists and read is granted.
# -w FILE                   FILE exists and write is granted.
# -x FILE                   FILE exists and execute is granted.
