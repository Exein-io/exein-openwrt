sudo apt-get update  
sudo apt-get -y install binutils build-essential bzip2 diffutils ecj fastjar file flex g++ gawk gcc gettext git grep java-propose-classpath libelf-dev libncurses5-dev libncursesw5-dev libssl-dev libz-dev make perl python python3 python3.5+ subversion unzip wget zlib1g-dev qemu

# cd shared/
git clone https://github.com/Exein-io/exein-openwrt.git  
cd exein-openwrt

cp config-arm.exein .config
./scripts/diffconfig.sh > configdiff
cp configdiff .config
make defconfig; make oldconfig
cat .config | grep -i exein

# ./scripts/feeds update -a
# ./scripts/feeds install -a

make download V=cs && make -j$(nproc) V=cs

sudo qemu-system-arm -M virt -nographic -smp 1 -kernel bin/targets/armvirt/32-glibc/openwrt-armvirt-32-zImage-initramfs -append "rootwait root=/dev/vda console=ttyAMA0 loglevel=0 norandmaps" -netdev tap,ifname=tap0,id=eth0 -device virtio-net-device,netdev=eth0