touch file1
gedit file1
cat file1
touch file2
gedit file2
ls
gcc ex2.c -o ex2.out
./ex2.out
sudo cp ex2.out lofsdisk/
cp /bin/{bash,ls} lofsdisk/
sudo cp /bin/{bash,ls} lofsdisk/
ldd /bin/bash
sudo mkdir lofsdisk/lib
cd lofsdisk/
ls
cd lib
sudo mkdir x86_64-linux-gnu
cd ..
sudo mkdir lib64
ls
cp {/lib/x86_64-linux-gnu/libtinfo.so.6,/lib/x86_64-linux-gnu/libdl.so.2,/lib/x86_64-linux-gnu/libc.so.6} lofsdisk/lib/x86_64-linux-gnu/
sudo cp {/lib/x86_64-linux-gnu/libtinfo.so.6,/lib/x86_64-linux-gnu/libdl.so.2,/lib/x86_64-linux-gnu/libc.so.6} lofsdisk/lib/x86_64-linux-gnu/
ldd /bin/ls
sudo cp {/lib/x86_64-linux-gnu/libselinux.so.1,/lib/x86_64-linux-gnu/libc.so.6,/lib/x86_64-linux-gnu/libpcre2-8.so.0,/lib/x86_64-linux-gnu/libdl.so.2,/lib/x86_64-linux-gnu/libpthread.so.0} lofsdisk/lib/x86_64-linux-gnu/
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/
sudo cp ex2.out lofsdisk/
cd lofsdisk/
ls
sudo mkdir bin
ls
sudo mv bash bin/
sudo mv ls bin/
cd ..
ldd /bin/cat
sudo cp /bin/cat lofsdisk/bin
ldd /bin/echo
sudo cp /bin/echo lofsdisk/bin
sudo chroot lofsdisk/
sudo cp lofsdisk/ex2.txt .
ls
cat ex2.txt
./ex2.out
cat ex2.txt
mv ex2.txt ex22.txt
./ex2.out
ls
gedit ex2.txt
gedit ex22.txt
gedit ex2.txt
rm ex22.txt
ls
sudo rm ex22.txt
cat ex2.txt
history > ex2.sh
