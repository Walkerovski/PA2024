g++ -std=c++20 day_2/Alchemik\ Bajtazar\ \[B\].cpp -o exe
g++ -std=c++20 testerka.cpp -o testerka
g++ -std=c++20 generator.cpp -o generator
# for i in {1..100}
# do
#     ./generator > input
#     ./exe < input > output
#     cat input > input.testerka
#     printf "\n" >> input.testerka
#     cat output >> input.testerka
#     ./testerka < input.testerka
#     if [ $? -ne 0 ]; then
#         break
#     fi
#     echo "OK: $i"
#     #diff -q --strip-trailing-cr output ./mod2
#     #/$i.out
# done
for i in {1..5}
do
    ./exe < inputs/$i.in > output
    cat inputs/$i.in > input.testerka
    printf "\n" >> input.testerka
    cat output >> input.testerka
    ./testerka < input.testerka
    if [ $? -ne 0 ]; then
        break
    fi
    echo "OK: $i"
    #diff -q --strip-trailing-cr output ./mod2
    #/$i.out
done
