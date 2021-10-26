touch ../week01/file.txt
link ../week01/file.txt _ex2.txt
ls -il
find ../ -inum 263085 > ex2.txt
cat ex2.txt 
find ../ -inum 263085 -exec rm {} \;
history > ex2.sh
