fallocate -l 50M lofs.img
ls
losetup -f
sudo losetup -f lofs.img
losetup -f
losetup -a
sudo mkfs.ext4 /dev/loop0
sudo mount /dev/loop0 lofsdisk/ 
history > ex1.sh
