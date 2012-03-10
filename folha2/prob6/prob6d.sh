echo "Programar todo o dia, não sabe o bem que lhe fazia" >> temp.txt
ln temp.txt temp1.txt
ln -s temp.txt temp2.txt
./prob6d .

rm temp*.txt
