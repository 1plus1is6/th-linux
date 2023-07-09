cd SourceCode
make
sudo cp ./th.out /usr/local/bin/th
cd ..
cd ..
cp -r th ~
cd ~/th
touch uninstall.sh
echo "cd /usr/local/bin" > uninstall.sh
echo "sudo rm th" >> uninstall.sh
echo "cd" >> uninstall.sh
echo "sudo rm -r th" >> uninstall.sh
chmod +x uninstall.sh
sudo rm install.sh