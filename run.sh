#!/bin/bash
search_bin=$(realpath tree)
cd ..
cd Construir
 
echo "0 preOrderIterativeSearch"
echo "1 preOrderRecursiveSearch"
echo "2 inOrderIterativeSearch"
echo "3 inOrderRecursiveSearch"
echo "4 postOrderIterativeSearch"
echo "5 postOrderRecursiveSearch"

for dir in $(ls)
do 
    echo "$dir"
    cd $(realpath $dir)
    for file in $(ls)
    do
        file_size="$(basename $file .txt)"
        file_path="$(realpath $file)"
        $search_bin $file_size $file_path
    done
    cd ..
done