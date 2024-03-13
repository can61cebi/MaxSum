file="max-toplam-v1.cpp"

    (time g++ -o "${file%.cpp}" "$file") 2> time.txt
    
    echo -e "\nVersiyon 1 icin zaman"
    echo "Time elapsed for $file:"
    
    while read -r line; do
        echo "$line"
    done < time.txt

    rm time.txt

file="max-sum-v2.cpp"

    (time g++ -o "${file%.cpp}" "$file") 2> time.txt
    
    echo -e "\nVersiyon 2 icin zaman"
    echo "Time elapsed for $file:"
    
    while read -r line; do
        echo "$line"
    done < time.txt

    rm time.txt