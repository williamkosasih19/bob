echo "############Tree TEST###############"
for i in $(seq 1 3);
do
echo testing with: $(cat treetest$i.txt)
../bin/bob/treetest < treetest$i.txt > out1.txt
../bin/cpp/treetest < treetest$i.txt > out2.txt
echo "my output : "
cat out1.txt
echo "expected output"
cat out2.txt
DIFF=$(diff out1.txt out2.txt)
echo $DIFF
if [ "$DIFF" != "" ] 
then
    echo "#####FAIL#####"
else 
    echo "#####PASS#####"
fi
done