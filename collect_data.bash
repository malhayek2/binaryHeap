#!/bin/bash

#!/bin/bash
size=2
for i in 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 
do
    # echo $number
    
    yes=$((size**i))
    echo $yes
    ./main $yes
    # ((number++))

done

