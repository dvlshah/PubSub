rm pub*.out sub*.out

echo "Creating Subscriber..."
g++ sub.cpp -o sub.out -std=c++11 -lzmq

max=$1

for i in `seq 2 $max`
do
    echo "Creating Publisher...:$i"
    g++ pub.cpp -o pub$i.out -std=c++11 -lzmq
done


