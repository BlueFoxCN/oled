# oled: main.cpp SSD1306.cpp
#	../../mips-openwrt-linux-g++ -std=c++0x -pthread -I/mnt/vdc/openwrt/attitude_adjustment/staging_dir/target-mips_r2_uClibc-0.9.33.2/usr/include -L/mnt/vdc/openwrt/attitude_adjustment/staging_dir/target-mips_r2_uClibc-0.9.33.2/usr/lib main.cpp SSD1306.cpp -o oled
oled: main.cpp gpio-operation.c SSD1306.cpp
	../../mips-openwrt-linux-g++ -std=c++0x -I/mnt/vdc/openwrt/attitude_adjustment/staging_dir/target-mips_r2_uClibc-0.9.33.2/usr/include -L/mnt/vdc/openwrt/attitude_adjustment/staging_dir/target-mips_r2_uClibc-0.9.33.2/usr/lib main.cpp gpio-operation.c SSD1306.cpp -o oled

clean:
	rm oled
