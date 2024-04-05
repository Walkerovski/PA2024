g++ -o B ./Day1/B.cpp
for((i = 0; i < 1000; i++))
do
    ./B < ./Day1/tests/in/orn$i.in > ./out
    if diff -qZB ./Day1/tests/out/orn$i.out ./out
    then
        echo $i
    else
        break
    fi
done