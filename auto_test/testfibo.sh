echo "############Fibo TEST###############"
for i in $(seq 1 7);
do
echo testing with: $(cat fibo$i.txt)
../bin/bob/fibo < fibo$i.txt > out1.txt
../bin/cpp/fibo < fibo$i.txt > out2.txt
echo "my output : "
echo $(cat out1.txt)
echo "expected output"
echo $(cat out2.txt)
DIFF=$(diff out1.txt out2.txt)
echo $DIFF
if [ "$DIFF" != "" ] 
then
    echo "#####FAIL#####"
else 
    echo "#####PASS#####"
fi
done