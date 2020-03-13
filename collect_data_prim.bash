#!/bin/bash

#!/bin/bash
#!/bin/bash

#!/bin/bash
size=10
for i in 1 2 3 4
do
    # echo $number
    yes="graph-${size}-${i}.txt"
    echo $yes
    ./main $yes
    # ((number++))

done
size=100
for i in 1 2 3 4
do
    # echo $number
    yes="graph-${size}-${i}.txt"
    echo $yes
    ./main $yes
    # ((number++))

done
size=1000
for i in 1 2 3 4
do
    # echo $number
    yes="graph-${size}-${i}.txt"
    echo $yes
    ./main $yes
    # ((number++))

done
size=10000
for i in 1 2 3 4
do
    # echo $number
    yes="graph-${size}-${i}.txt"
    echo $yes
    ./main $yes
    # ((number++))

done

size=20000
for i in 1 2 3 4
do
    # echo $number
    yes="graph-${size}-${i}.txt"
    echo $yes
    ./main $yes
    # ((number++))

done


