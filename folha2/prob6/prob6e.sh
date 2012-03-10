echo "Programar todo o dia, não sabe o bem que lhe fazia" >> temp.txt
ln temp.txt temp1.txt
ln -s temp.txt temp2.txt

echo "removing temp.txt"
echo "-------"
rm temp.txt
ls -la
echo "cat temp2.txt"
cat temp2.txt

echo "cat temp1.txt"
cat temp1.txt
sleep 10s

echo "removing temp2.txt"
echo "-------"
rm temp2.txt
ls -la
echo "cat temp1.txt"
cat temp1.txt
sleep 10s

rm temp1.txt

#conclusion: when we remove the source file of hardlink, the harded file still points to data.
# in the other hand, when we remove the source file of symlink, the sym file is useless

